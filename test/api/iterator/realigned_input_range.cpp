//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/iterator/realigned_input_range.hpp>
#include <boost/align/aligned_allocator.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/splat.hpp>
#include <boost/range.hpp>

#include <simd_test.hpp>

#include <vector>

template <typename T>
using allocator = boost::alignment::aligned_allocator<T>;

template<typename Range, typename Out>
inline Out mycopy(Range const& r, Out dst)
{
  typedef typename std::iterator_traits<Out>::value_type T;
  typedef typename boost::range_iterator<Range>::type it_t;

  it_t begin = boost::begin(r);
  it_t end = boost::end(r);

  for(; begin != end; ++begin) *dst++ = T(*begin);

  return dst;
}

STF_CASE_TPL("distance", STF_NUMERIC_TYPES)
{
  using std::iterator_traits;
  using boost::simd::realigned_input_range;
  using boost::simd::pack;

  // Take soemthign aligned and chirurgically unalign it
  std::vector<T, allocator<T> > data(pack<T>::static_size*4);
  typedef boost::iterator_range<typename std::vector<T, allocator<T> >::iterator> r_t;

  {
    STF_EQUAL( std::distance ( boost::begin(realigned_input_range(data))
                                  , boost::end  (realigned_input_range(data))
                                  )
                  , 4
                  );
  }

  {
    r_t r = boost::make_iterator_range( data.begin() + 1, data.end() );

    STF_EQUAL( std::distance ( boost::begin(realigned_input_range(r))
                                  , boost::end  (realigned_input_range(r))
                                  )
                  , 3
                  );
  }

  {
    r_t r = boost::make_iterator_range( data.begin(), data.end() -1 );

    STF_EQUAL( std::distance ( boost::begin(realigned_input_range(r))
                                  , boost::end  (realigned_input_range(r))
                                  )
                  , 3
                  );
  }

  {
    r_t r = boost::make_iterator_range( data.begin() + 1, data.end() -1 );

    STF_EQUAL( std::distance ( boost::begin(realigned_input_range(r))
                                  , boost::end  (realigned_input_range(r))
                                  )
                  , 2
                  );
  }
}

STF_CASE_TPL("iteration", STF_NUMERIC_TYPES)
{
  using std::iterator_traits;
  using boost::simd::realigned_input_range;
  using boost::simd::pack;
  using boost::simd::splat;
  using boost::begin;
  using boost::end;

  std::vector< pack<T> > dst(3);
  std::vector< pack<T> > ref(3);
  std::vector<T, allocator<T> >  data(pack<T>::static_size*4-1);

  for(std::size_t i=0;i<data.size();i++)
    data[i] = i/pack<T>::static_size+1;

  for(std::size_t i=0;i<ref.size();i++)
    ref[i] = splat< pack<T> >(i+1);

  mycopy( realigned_input_range(data), dst.begin());

  for ( std::size_t i = 0 ; i < ref.size() ; ++i )
    STF_EQUAL( ref[i], dst[i] );
}

//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/c180.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check c180 behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::c180;
  using boost::simd::C180;

  STF_TYPE_IS(decltype(C180<T>()), T);
  STF_EQUAL(C180<T>(), T(180));
  STF_EQUAL(c180( as(T{}) ),T(180));
}

STF_CASE_TPL( "Check c180 behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::c180;
  using boost::simd::C180;

  STF_TYPE_IS(decltype(C180<T>()), T);
  STF_IEEE_EQUAL(C180<T>(), T(180));
  STF_IEEE_EQUAL(c180( as(T{}) ), T(180));
}

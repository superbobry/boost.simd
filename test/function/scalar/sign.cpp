//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/sign.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" sign real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sign;
  using r_t = decltype(sign(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(sign(bs::Inf<T>()), bs::One<r_t>());
  STF_EQUAL(sign(bs::Minf<T>()), bs::Mone<r_t>());
  STF_IEEE_EQUAL(sign(bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(sign(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(sign(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(sign(bs::Zero<T>()), bs::Zero<r_t>());
}

STF_CASE_TPL (" sign unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sign;
  using r_t = decltype(sign(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(sign(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(sign(bs::Zero<T>()), bs::Zero<r_t>());
}

STF_CASE_TPL (" signsigned_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sign;
  using r_t = decltype(sign(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(sign(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(sign(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(sign(bs::Zero<T>()), bs::Zero<r_t>());
}

//==================================================================================================
/*!

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/sinhc.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/function/sinh.hpp>

STF_CASE_TPL (" sinhc",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sinhc;
  using r_t = decltype(sinhc(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(sinhc(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(sinhc(bs::Minf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(sinhc(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(sinhc(bs::Zero<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(sinhc(bs::One<T>()), bs::sinh(bs::One<r_t>()), 0);
  STF_ULP_EQUAL(sinhc(bs::Two<T>()), bs::sinh(bs::Two<T>())*bs::Half<T>(), 0);
  STF_ULP_EQUAL(sinhc(bs::Mone<T>()), bs::sinh(bs::One<r_t>()), 0);
}

//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/round.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/mhalf.hpp>
#include <boost/simd/constant/maxflint.hpp>
#include <boost/simd/function/next.hpp>
#include <boost/simd/function/prev.hpp>

STF_CASE_TPL (" round real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::round;
  using bs::next;
  using bs::prev;
  using r_t = decltype(round(T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(round(bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(round(bs::Minf<T>()), bs::Minf<r_t>());
  STF_IEEE_EQUAL(round(bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(round(bs::Mhalf<T>()), bs::Mone<r_t>());
  STF_EQUAL(round(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(round(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(round(bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(round(bs::Maxflint<T>()-bs::Half<T>()),bs::Maxflint<T>());
  STF_EQUAL(round(bs::Maxflint<T>()),bs::Maxflint<T>());
  STF_EQUAL(round(T(1.4)), T(1));
  STF_EQUAL(round(T(1.5)), T(2));
  STF_EQUAL(round(T(1.6)), T(2));
  STF_EQUAL(round(T(2.5)), T(3));
  STF_EQUAL(round(T(-1.4)), T(-1));
  STF_EQUAL(round(T(-1.5)), T(-2));
  STF_EQUAL(round(T(-1.6)), T(-2));
  STF_EQUAL(round(T(-2.5)), T(-3));
  STF_EQUAL(round(bs::Half<T>()), bs::One<r_t>());
  STF_EQUAL(round(prev(prev(bs::Half<T>()))),  bs::Zero<T>());
  STF_EQUAL(round(prev(bs::Half<T>())),  bs::Zero<T>());
  STF_EQUAL(round(     bs::Half<T>()) ,  bs::One <T>());
  STF_EQUAL(round(next(bs::Half<T>())),  bs::One <T>());
  T z = bs::Maxflint < T>()/T(2)+T(1);
  STF_EQUAL(round(z), z);

} // end of test for floating_

STF_CASE_TPL (" round real2",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::round;
  using bs::next;
  using bs::prev;
  using r_t = decltype(round(T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(round(bs::Inf<T>(), 2), bs::Inf<r_t>());
  STF_EQUAL(round(bs::Minf<T>(), 2), bs::Minf<r_t>());
  STF_IEEE_EQUAL(round(bs::Nan<T>(), 2), bs::Nan<r_t>());
#endif
  STF_EQUAL(round(bs::Mhalf<T>(), 2), bs::Mhalf<r_t>());
  STF_EQUAL(round(bs::Mone<T>(), 2), bs::Mone<r_t>());
  STF_EQUAL(round(bs::One<T>(), 2), bs::One<r_t>());
  STF_EQUAL(round(bs::Zero<T>(), 2), bs::Zero<r_t>());
  STF_EQUAL(round(bs::Maxflint<T>()-bs::Half<T>(), 2),bs::Maxflint<T>());
  STF_EQUAL(round(bs::Maxflint<T>(), 2),bs::Maxflint<T>());
  STF_EQUAL(round(T(1.44), 1), T(1.4));
  STF_EQUAL(round(T(1.45), 1), T(1.5));
  STF_EQUAL(round(T(1.46), 1), T(1.5));
  STF_EQUAL(round(T(2.45), 1), T(2.5));
  STF_EQUAL(round(T(-1.44), 1), T(-1.4));
  STF_EQUAL(round(T(-1.45), 1), T(-1.5));
  STF_EQUAL(round(T(-1.46), 1), T(-1.5));
  STF_EQUAL(round(T(-2.45), 1), T(-2.5));
  STF_ULP_EQUAL(round(T(145), -2), T(100), 0.5);
  STF_ULP_EQUAL(round(T(150), -2), T(200), 0.5);
  STF_ULP_EQUAL(round(T(156), -2), T(200), 0.5);
  STF_ULP_EQUAL(round(T(250), -2), T(300), 0.5);
  STF_ULP_EQUAL(round(T(-145), -2), T(-100), 0.5);
  STF_ULP_EQUAL(round(T(-155), -2), T(-200), 0.5);
  STF_ULP_EQUAL(round(T(-156), -2), T(-200), 0.5);
  STF_ULP_EQUAL(round(T(-255), -2), T(-300), 0.5);
} // end of test for floating_



STF_CASE_TPL (" roundunsigned_int__1_0",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::round;
  using r_t = decltype(round(T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_EQUAL(round(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(round(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" roundsigned_int__1_0",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::round;
  using r_t = decltype(round(T()));

  // return type conformity test
  STF_TYPE_IS( r_t, T );

  // specific values tests
  STF_EQUAL(round(bs::Mone<T>()), bs::Mone<r_t>());
  STF_EQUAL(round(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(round(bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_

//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/ifnot_inc.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" ifnot_inc signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ifnot_inc;

  // return type conformity test
  STF_EXPR_IS( ifnot_inc(T(), T()), T);

  // specific values tests
  STF_EQUAL(ifnot_inc(bs::Zero<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(ifnot_inc(bs::Zero<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(ifnot_inc(bs::Zero<T>(), bs::Zero<T>()), bs::One<T>());
  STF_EQUAL(ifnot_inc(bs::One<T>(), bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(ifnot_inc(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(ifnot_inc(bs::One<T>(), bs::Zero<T>()), bs::Zero<T>());
}

STF_CASE_TPL (" ifnot_inc unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ifnot_inc;

  // return type conformity test

  // specific values tests
  STF_EXPR_IS( ifnot_inc(T(), T()), T);

  // specific values tests
  STF_EQUAL(ifnot_inc(bs::Zero<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(ifnot_inc(bs::Zero<T>(), bs::Valmax<T>()), bs::Zero<T>());
  STF_EQUAL(ifnot_inc(bs::Zero<T>(), bs::Zero<T>()), bs::One<T>());
  STF_EQUAL(ifnot_inc(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(ifnot_inc(bs::One<T>(), bs::Zero<T>()), bs::Zero<T>());}

STF_CASE_TPL(" ifnot_inc _floating", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ifnot_inc;

  // return type conformity test
  STF_EXPR_IS( ifnot_inc(T(), T()), T);

  // specific values tests
  STF_EQUAL(ifnot_inc(bs::Zero<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(ifnot_inc(bs::Zero<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(ifnot_inc(bs::Zero<T>(), bs::Valmax<T>()), bs::Valmax<T>());
  STF_EQUAL(ifnot_inc(bs::Zero<T>(), bs::Zero<T>()), bs::One<T>());
  STF_EQUAL(ifnot_inc(bs::One<T>(), bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(ifnot_inc(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(ifnot_inc(bs::One<T>(), bs::Zero<T>()), bs::Zero<T>());
}

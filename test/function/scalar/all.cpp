//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/all.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

STF_CASE_TPL ( "all", STF_ALL_TYPES)
{
  namespace bs = boost::simd;
  using bs::all;

  STF_EQUAL( all(T(1)) , true  );
  STF_EQUAL( all(T(0)), false );
}


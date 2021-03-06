//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/gold.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check gold behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::gold;
  using boost::simd::Gold;

  STF_TYPE_IS(decltype(Gold<T>()), T);
  STF_EQUAL(Gold<T>(), T(1));
  STF_EQUAL(gold( as(T{}) ),T(1));
}

STF_CASE_TPL( "Check gold behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::gold;
  using boost::simd::Gold;

  STF_TYPE_IS(decltype(Gold<T>()), T);
  STF_ULP_EQUAL(Gold<T>()+T(1), Gold<T>()*Gold<T>(), 1);
  STF_GREATER(  Gold<T>(), T(1));
  auto z = gold( as(T{}));
  STF_ULP_EQUAL((z+T(1)),z*z, 1);

}

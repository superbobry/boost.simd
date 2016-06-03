//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_ONEPLUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_ONEPLUS_HPP_INCLUDED

#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/function/is_not_equal.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/if_plus.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( oneplus_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_<bd::arithmetic_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      return plus(a0, One<A0>());
    }
  };
} } }

#include <boost/simd/arch/common/generic/function/oneplus_s.hpp>

#endif

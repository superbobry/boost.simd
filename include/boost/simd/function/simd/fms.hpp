//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================

#ifndef BOOST_SIMD_FUNCTION_SIMD_FMS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_FMS_HPP_INCLUDED

#include <boost/simd/function/scalar/fms.hpp>
#include <boost/simd/arch/common/generic/function/autodispatcher.hpp>

#if defined(BOOST_HW_SIMD_X86_OR_AMD_AVAILABLE)
#  if BOOST_HW_SIMD_X86_OR_AMD >= BOOST_HW_SIMD_X86_AMD_FMA4_VERSION
#    include <boost/simd/arch/x86/fma4/simd/function/fms.hpp>
#  endif
#  if BOOST_HW_SIMD_X86_OR_AMD >= BOOST_HW_SIMD_X86_FMA3_VERSION
#    include <boost/simd/arch/x86/fma3/simd/function/fms.hpp>
#  endif
#endif

#endif

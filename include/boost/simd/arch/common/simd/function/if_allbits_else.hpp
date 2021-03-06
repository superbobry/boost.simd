//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IF_ALLBITS_ELSE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IF_ALLBITS_ELSE_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/meta/is_bitwise_logical.hpp>
#include <boost/simd/function/simd/genmask.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/constant/allbits.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(if_allbits_else_
                          , (typename A0, typename A1, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::unspecified_<A0>, X>
                          , bs::pack_<bd::arithmetic_<A1>, X>
                          )
   {
     template < typename A0_>
     typename enable_if< bs::is_bitwise_logical<A0_>, A1>::type
     BOOST_FORCEINLINE operator()(A0_ const& a0, A1 const& a1) const BOOST_NOEXCEPT
     {
       return bitwise_or(a1, genmask(a0));
     }

     template<class A0_>
     typename disable_if< bs::is_bitwise_logical<A0_>, A1>::type
     BOOST_FORCEINLINE operator()(A0_ const& a0, A1 const& a1) const BOOST_NOEXCEPT
     {
       return if_else(a0, Allbits<A1>(), a1);
     }
   };

} } }

#endif


//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_TOUINT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_TOUINT_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/inc.hpp>
#include <boost/simd/function/simd/is_less.hpp>
#include <boost/simd/function/simd/minus.hpp>
#include <boost/simd/function/simd/plus.hpp>
#include <boost/simd/function/simd/splat.hpp>
#include <boost/simd/function/simd/toint.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(touint_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::integer_<A0>, X>
                          )
   {
     using result = bd::as_integer_t<A0, unsigned> ;
     BOOST_FORCEINLINE result operator()(A0 const& a0) const BOOST_NOEXCEPT
     {
       return bitwise_cast<result>(a0);
     }
   };

   BOOST_DISPATCH_OVERLOAD(touint_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
     using result = bd::as_integer_t<A0, unsigned> ;
     BOOST_FORCEINLINE result operator()(A0 const& a0) const BOOST_NOEXCEPT
     {
       using signed_integer = bd::as_integer_t<typename bd::scalar_of_t<A0>, signed>;
       A0 sign_f = inc(splat<A0>(Valmax<signed_integer>()));
       result sign_i = inc(splat<result>(Valmax<signed_integer>()));
       return if_else(is_less(a0, sign_f)
                     , bitwise_cast<result>(toint(a0))
                     , bitwise_cast<result>(toint(a0 - sign_f)) + sign_i
                     );
     }
   };

} } }

#endif


//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ROL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ROL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-bitwise
    Function object implementing rol capabilities

    Returns the first entry rotated left
    by the absolute value of the second entry.

    @par semantic:
    For any given value @c x of type @c T, n  of type @c I:

    @code
    T r = rol(x, n);
    @endcode

    @par Note
    This function asserts if the integral parameter is out of range

    @see  ror, rrol, rror

  **/
  const boost::dispatch::functor<tag::rol_> rol = {};
} }
#endif

#include <boost/simd/function/scalar/rol.hpp>
#include <boost/simd/function/simd/rol.hpp>

#endif

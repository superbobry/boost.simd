//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SHIFT_LEFT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SHIFT_LEFT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-operator
    Function object implementing shift_left capabilities

    return left shift of the first operand by the second
    that must be of integer type and of the same number
    of elements as the first parameter

    Infix notation can be used with operator '<<'

    @par Semantic:

    For every parameters of types respectively T, N:

    @code
    T0r = shift_left(x,n);
    @endcode

    is similar to:

    @code
    T r = x << n;
    @endcode

    @par Alias:
    @c shl, @c shli

    @see  shift_right, shr, rshl, rshr, rol, ror

  **/
  const boost::dispatch::functor<tag::shift_left_> shift_left = {};
} }
#endif

#include <boost/simd/function/scalar/shift_left.hpp>
#include <boost/simd/function/simd/shift_left.hpp>

#endif

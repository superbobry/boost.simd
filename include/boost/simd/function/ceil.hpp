//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CEIL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CEIL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
  @ingroup group-arithmetic
    Function object implementing ceil capabilities

   Computes the ceil of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = ceil(x);
    @endcode

    computes the smallest integral value of type @c T greater or equal to @c x.

    @par Decorators

    std_ for floating entries

    @see  floor, round, round2even, trunc, iceil

  **/
{
} }
#endif

#include <boost/simd/function/scalar/ceil.hpp>
#include <boost/simd/function/simd/ceil.hpp>

#endif

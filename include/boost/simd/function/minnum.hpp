//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MINNUM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINNUM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing minnum capabilities

     Returns the minimum value, ignoring nans.

    @par Semantic:

    @code
    T r = minnum(x,y);
    @endcode

    is similar to:

    @code
    T r =     T r = (is_nan(x) ? y : (isnan(y) ? x : min(x, y));;
    @endcode

    @par Alias:
    @c fmin

    With the std_ decorator std_(minnum)(x, y) calls the stdlibc++ function std::fmin.

    @par Decorators

    std_ for floating entries

  **/
  const boost::dispatch::functor<tag::minnum_> minnum = {};
} }
#endif

#include <boost/simd/function/scalar/minnum.hpp>
#include <boost/simd/function/simd/minnum.hpp>

#endif

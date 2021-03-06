//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NOT_GREATER_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NOT_GREATER_EQUAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing is_not_greater_equal capabilities

    Returns @ref True if x is not greater or equal to y else returns @ref False.

    @par Semantic:

    @code
    as_logical_t<T> r = is_not_greater_equal(x,y);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = !(x >= y);
    @endcode

    @par Note:

    Due to existence of nan, this is not equivalent to @c is_less(x)
    for floating types

    @par Alias:

    @c is_nge

  **/
  const boost::dispatch::functor<tag::is_not_greater_equal_> is_not_greater_equal = {};
} }
#endif

#include <boost/simd/function/scalar/is_not_greater_equal.hpp>
#include <boost/simd/function/simd/is_not_greater_equal.hpp>

#endif

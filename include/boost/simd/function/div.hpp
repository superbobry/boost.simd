//==================================================================================================
/*!
  @file

  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIV_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIV_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-operator

    Perform the quotient of two parameters of the same type with or without options.

    @par Semantic

    For any value @c a and @c b of type @c T,

    @code
    T r = div({option, }a, b);
    @endcode

    returns the quotient of @c a by @c b according to the option

    if there is no option the call is equivalent to divides(a, b),  else
    option can be ceil, floor, fix, round, round2even (in the namespace booost::simd)
    and provide the same result as the calls divceil(a, b), divfloor(a, b),
    divfix(a, b), divround(a, b).

    @return The quotient of the two parameters.
  **/
  template<typename T> auto div({Option const & o, T const& a, T const& b);

  namespace functional
  {
    /*!
      @ingroup group-callable-operator

      Perform the quotient of two parameters of the same type.


      Function object tied to boost::simd::div

      @see boost::simd::div
    **/
    const boost::dispatch::functor<tag::div_> div = {};
  }
} }
#endif

#include <boost/simd/function/scalar/div.hpp>
#include <boost/simd/function/simd/div.hpp>


#endif

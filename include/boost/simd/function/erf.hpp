//==================================================================================================
/*!
  @file
  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ERF_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ERF_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
  @ingroup group-euler
    Function object implementing erf capabilities

   Computes the error function:
   \f$\displaystyle \frac{2}{\sqrt\pi}\int_0^{x} e^{-t^2}\mbox{d}t\f$

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = erf(x);
    @endcode

    @par Decorators

    std_ for floating entries

    @see erfc,  erfcx

  **/
  const boost::dispatch::functor<tag::erf_> erf = {};
} }
#endif

#include <boost/simd/function/scalar/erf.hpp>
#include <boost/simd/function/simd/erf.hpp>

#endif

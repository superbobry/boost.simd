//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_EXPONENTIAL_HPP_INCLUDED
#define BOOST_SIMD_EXPONENTIAL_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-functions
    @defgroup group-exponential Exponential Functions

    Those functions provides algorithms for computing exponentials and logarithms.
  **/

  /*!
    @ingroup group-callable
    @defgroup group-callable-exponential Exponential Callable Objects
    Callable objects version of @ref group-exponential

    Their specific semantic limitations are similar to those of their function
    equivalents as described in the @ref group-exponential section.
  **/

} }

#include <boost/simd/function/cbrt.hpp>
#include <boost/simd/function/exp10.hpp>
#include <boost/simd/function/exp2.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/function/expm1.hpp>
#include <boost/simd/function/exprecnegc.hpp>
#include <boost/simd/function/exprecneg.hpp>
#include <boost/simd/function/expx2.hpp>
#include <boost/simd/function/log10.hpp>
#include <boost/simd/function/log2.hpp>
#include <boost/simd/function/log.hpp>
#include <boost/simd/function/nthroot.hpp>
#include <boost/simd/function/pow2.hpp>
#include <boost/simd/function/pow_abs.hpp>
#include <boost/simd/function/pow.hpp>
#include <boost/simd/function/significants.hpp>

#endif

//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_PIO_2LO_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_PIO_2LO_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct pio_2lo_ : boost::dispatch::constant_value_<pio_2lo_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,pio_2lo_,boost::dispatch::constant_value_<pio_2lo_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0XB33BBD2EUL, 0X3C91A62633145C07ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,pio_2lo_);
  }

  namespace detail
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::pio_2lo_,pio_2lo);
  }

  template<typename T> BOOST_FORCEINLINE auto Pio_2lo()
  BOOST_NOEXCEPT_DECLTYPE(detail::pio_2lo( boost::dispatch::as_<T>{}))
  {
    return detail::pio_2lo( boost::dispatch::as_<T>{} );
  }
} }

#endif

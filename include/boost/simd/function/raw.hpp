//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_RAW_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_RAW_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/decorator.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  struct raw_tag : decorator_<raw_tag>
  {
    using parent = decorator_<raw_tag>;
  };

  const detail::decorator<raw_tag> raw_ = {};
} }

#endif

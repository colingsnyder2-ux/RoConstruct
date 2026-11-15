// native-flags: /O2 /GS- /EHsc /MD /I{headers}/../../../tools/libs/boost_1_40_0 /I{headers}/../../../tools/libs/boost_1_40_0/libs/regex/src
// 2008-06 native Boostinstances (inactive): upstream tools/libs/boost_1_40_0/libs/regex/src/instances.cpp, verbatim.
/*
 *
 * Copyright (c) 1998-2002
 * John Maddock
 *
 * Use, modification and distribution are subject to the 
 * Boost Software License, Version 1.0. (See accompanying file 
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 *
 */

 /*
  *   LOCATION:    see http://www.boost.org for most recent version.
  *   FILE:        instances.cpp
  *   VERSION:     see <boost/version.hpp>
  *   DESCRIPTION: regex narrow character template instances.
  */

#define BOOST_REGEX_SOURCE

#include <boost/regex/config.hpp>

#if !defined(BOOST_REGEX_NO_EXTERNAL_TEMPLATES)
#define BOOST_REGEX_NARROW_INSTANTIATE

#ifdef __BORLANDC__
#pragma hrdstop
#endif

#include <boost/regex.hpp>

#endif

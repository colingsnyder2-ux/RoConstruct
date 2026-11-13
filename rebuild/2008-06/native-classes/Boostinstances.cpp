// native-flags: /O2 /GS- /EHsc /MD /I{headers}/../../../tools/libs/zlib-1.2.3 /I{headers}/../../../tools/libs/boost_1_34_1/libs/regex/src
// 2008-06 native Boostinstances (inactive): upstream tools/libs/boost_1_34_1/libs/regex/src/instances.cpp, verbatim.
// >>> native-status (generated) -- do not edit >>>
// Boostinstances | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src b3eb4a3f | roc native-status --write
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

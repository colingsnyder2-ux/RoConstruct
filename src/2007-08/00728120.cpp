// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS /EHsc /MD
// roc-lib: rbxgs roc_espeon_boost133_signals_core_87ff765581a30b8d.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL 1
#define _MT 1
#define BOOST_SIGNALS_SOURCE
#pragma include_alias(<boost/signals/signal_template.hpp>, <../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp>)
#pragma include_alias("boost/signals/signal_template.hpp", "../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp")
#include "roc_espeon_boost133_header_d432d72f8740aec3.cpp"
#include "roc_espeon_boost133_header_d9eb4711b7fc841c.cpp"
#include "roc_espeon_boost133_signals_header_be197e98651271fa.cpp"
// Boost.Signals library

// Copyright Douglas Gregor 2001-2004. Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// For more information, see http://www.boost.org

#define BOOST_SIGNALS_SOURCE

#include <boost/signals/trackable.hpp>
#include <algorithm>

namespace boost {
  namespace BOOST_SIGNALS_NAMESPACE {
    void trackable::signal_disconnected(void* obj, void* data)
    {
      trackable* self = reinterpret_cast<trackable*>(obj);
      connection_iterator* signal =
        reinterpret_cast<connection_iterator*>(data);

      // If we're dying, don't bother erasing the connection from the list;
      // it'll be gone anyway
      if (!self->dying) {
        self->connected_signals.erase(*signal);
      }

      // This iterator pointer won't ever be used again
      delete signal;
    }

    void
    trackable::signal_connected(connection c,
                                BOOST_SIGNALS_NAMESPACE::detail::bound_object& binding) const
    {
      // Insert the connection
      connection_iterator pos =
        connected_signals.insert(connected_signals.end(), c);

      // Make this copy of the object disconnect when destroyed
      pos->set_controlling();

      binding.obj = const_cast<void*>(reinterpret_cast<const void*>(this));
      binding.data = reinterpret_cast<void*>(new connection_iterator(pos));
      binding.disconnect = &signal_disconnected;
    }

    trackable::~trackable()
    {
      dying = true;
    }
  } // end namespace BOOST_SIGNALS_NAMESPACE
}

#ifndef BOOST_MSVC
// Explicit instantiations to keep in the library
template class std::list<boost::BOOST_SIGNALS_NAMESPACE::connection>;
#endif

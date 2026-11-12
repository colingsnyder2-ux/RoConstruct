// native-flags: /O2 /GS- /EHsc /MD /I{headers}/../../../tools/libs/zlib-1.2.3 /I{headers}/../../../tools/libs/boost_1_34_1/libs/signals/src
// 2008-06 native Boosttrackable (inactive): upstream tools/libs/boost_1_34_1/libs/signals/src/trackable.cpp, verbatim.
// Boost.Signals library

// Copyright Douglas Gregor 2001-2004. Use, modification and
// distribution is subject to the Boost Software License, Version
// 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// For more information, see http://www.boost.org

// >>> native-status (generated) -- do not edit >>>
// Boosttrackable | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 8e388ccf | roc native-status --write
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

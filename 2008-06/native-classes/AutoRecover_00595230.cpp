// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: boost 1.34.1 signals connection; header supplies layout (con at +4, controlling_connection at +8 of shared_count).
#include <boost/signals/connection.hpp>
#include <cassert>

namespace boost {
  namespace signals {

    void connection::disconnect() const
    {
      if (this->connected()) {
        // Hold a reference: 'this' may disappear during disconnect.
        shared_ptr<detail::basic_connection> local_con = con;

        void (*signal_disconnect)(void*, void*) = local_con->signal_disconnect;

        // Clear before calling to avoid infinite loop.
        local_con->signal_disconnect = 0;

        signal_disconnect(local_con->signal, local_con->signal_data);

        typedef std::list<detail::bound_object>::iterator iterator;
        for (iterator i = local_con->bound_objects.begin();
             i != local_con->bound_objects.end(); ++i) {
          assert(i->disconnect != 0);
          i->disconnect(i->obj, i->data);
        }
      }
    }

  }
}

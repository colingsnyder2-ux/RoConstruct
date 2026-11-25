// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "boost/shared_ptr.hpp"
#include "boost/function.hpp"
#include "boost/signals.hpp"
#include <functional>

namespace RBX { class Instance; }

// Vendor code: boost::signal1<...>::connect(const slot_type&, connect_position)
// as instantiated in rbxgs v8datamodel/FlagStand.cpp. The body comes from the
// boost signals template (signal_template.hpp):
//
//   if (!in_slot.is_active())
//     return signals::connection();
//   any slot = in_slot.get_slot_function();
//   return impl->connect_slot(slot, stored_group(), in_slot.get_data(), at);
//
// INFERRED: emitting the exact template instantiation reproduces the vendor
// code (same statements and the same inlining).
template boost::signals::connection
boost::signal1<
    void,
    boost::shared_ptr<RBX::Instance>,
    boost::last_value<void>,
    int,
    std::less<int>,
    boost::function<void (boost::shared_ptr<RBX::Instance>)>
>::connect(
    const boost::slot< boost::function<void (boost::shared_ptr<RBX::Instance>)> >& in_slot,
    boost::signals::connect_position at);

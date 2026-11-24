// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <functional>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/signal.hpp>

namespace RBX { class Instance; }

// INFERRED: this target is the vendor (boost.signals) template member
//   signal1<void, shared_ptr<Instance>, last_value<void>, int, std::less<int>,
//           function<void(shared_ptr<Instance>)> >::connect(const slot_type&, connect_position)
// as instantiated from v8datamodel/FlagStand.cpp. Its body is:
//
//   if (!in_slot.is_active()) return signals::connection();
//   return impl->connect_slot(in_slot.get_slot_function(), stored_group(),
//                             in_slot.get_data(), at);
//
// We reproduce it by explicitly instantiating that exact member, so the
// compiler emits the vendor implementation with its real mangled name.

typedef boost::signal1<
    void,
    boost::shared_ptr<RBX::Instance>,
    boost::last_value<void>,
    int,
    std::less<int>,
    boost::function<void (boost::shared_ptr<RBX::Instance>)>
> InstanceSignal1;

template boost::signals::connection
InstanceSignal1::connect(const InstanceSignal1::slot_type& in_slot,
                         boost::signals::connect_position at);

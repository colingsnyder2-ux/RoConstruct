// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <boost/shared_ptr.hpp>
#include <boost/signal.hpp>

namespace RBX { class Instance; }

// This target is the vendor boost::signal1<...>::connect(const slot_type&, connect_position).
// The vendor template body is:
//   if (!in_slot.is_active()) return signals::connection();
//   return impl->connect_slot(in_slot.get_slot_function(), stored_group(),
//                             in_slot.get_data(), at);
// The template arguments below are the defaults spelled out in the mangled name:
// last_value<void>, int, std::less<int>, function<void(shared_ptr<Instance>)>.
// INFERRED: emitting it through an explicit instantiation of the boost template
// reproduces the vendor statements and inlining.
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

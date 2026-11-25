// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
//
// Vendor code: boost::signal1<void, boost::shared_ptr<RBX::Instance> >::connect(
//     const slot_type& in_slot, signals::connect_position at)
// Instantiated in rbxgs v8datamodel/FlagStand.cpp.
//
// Boost 1.34 signal_template.hpp body:
//   if (!in_slot.is_active()) {
//     return signals::connection();
//   }
//   return impl->connect_slot(in_slot.get_slot_function(), any(),
//                             in_slot.get_data(), at);
//
// connect_slot is reached through the out-of-line callee 0x56a900, and the
// get_data call goes to 0x4915b0. The boost::any construction from the
// boost::function goes to 0x556060. All three come from the boost headers
// via the template body, so no fn_ externs are needed here.

#include <boost/shared_ptr.hpp>
#include <boost/signal.hpp>
#include <boost/function.hpp>
#include <functional>

namespace RBX { class Instance; }

// INFERRED: the target is the explicit instantiation of the vendor template member.
// The template parameters come from the mangled name:
// signal1<void, shared_ptr<Instance>, last_value<void>, int, std::less<int>,
//         function<void (shared_ptr<Instance>)> >.
template boost::signals::connection
boost::signal1<
    void,
    boost::shared_ptr<RBX::Instance>,
    boost::last_value<void>,
    int,
    std::less<int>,
    boost::function<void (boost::shared_ptr<RBX::Instance>)>
>::connect(const slot_type& in_slot, boost::signals::connect_position at);

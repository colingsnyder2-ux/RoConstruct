// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
//
// Vendor code: boost::signal1<void, shared_ptr<RBX::Instance>, ...>::connect
// (instantiated in rbxgs v8datamodel/FlagStand.cpp).
//
// The body is boost's own template implementation:
//
//   if (!in_slot.is_active())
//     return signals::connection();
//   return impl->connect_slot(in_slot.get_slot_function(), any(),
//                             in_slot.get_data(), at);
//
// The function is emitted by explicitly instantiating that member
// rather than re-implementing it by hand.

#include <functional>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/signal.hpp>

namespace RBX { class Instance; }

// INFERRED: the template arguments are recovered from the mangled name
// ?connect@?$signal1@XV?$shared_ptr@VInstance@RBX@@@boost@@U?$last_value@X@2@HU?$less@H@std@@V?$function@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@ZV?$allocator@X@std@@@2@@boost@@
// i.e. R = void, T1 = shared_ptr<Instance>, Combiner = last_value<void>,
//      Group = int, GroupCompare = std::less<int>,
//      SlotFunction = boost::function<void(shared_ptr<Instance>)>.
template boost::signals::connection
boost::signal1<
    void,
    boost::shared_ptr<RBX::Instance>,
    boost::last_value<void>,
    int,
    std::less<int>,
    boost::function<void(boost::shared_ptr<RBX::Instance>)>
>::connect(const slot_type& in_slot, boost::signals::connect_position at);

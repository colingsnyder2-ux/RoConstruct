// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Vendor code: boost::signal1<void, shared_ptr<RBX::Instance>, ...>::connect(const slot_type&, connect_position)
// Instantiated from rbxgs v8datamodel/FlagStand.cpp. The body is the stock boost implementation:
//
//   if (!in_slot.is_active()) {
//     return signals::connection();
//   }
//   return impl->connect_slot(in_slot.get_slot_function(), any(),
//                             in_slot.get_data(), at);
//
// It is reproduced here by explicitly instantiating that member, so that the compiler emits
// the same inlined is_active() check, any(function) construction, get_data() call,
// connect_slot() call and the shared_ptr / any destructors.

#include <functional>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/signal.hpp>

namespace RBX { class Instance; }

// INFERRED: the template arguments are taken from the mangled name
// ?connect@?$signal1@XV?$shared_ptr@VInstance@RBX@@@boost@@U?$last_value@X@2@HU?$less@H@std@@V?$function@$$A6AXV?$shared_ptr@VInstance@RBX@@@boost@@@ZV?$allocator@X@std@@@2@@boost@@...
typedef boost::signal1<
    void,
    boost::shared_ptr<RBX::Instance>,
    boost::last_value<void>,
    int,
    std::less<int>,
    boost::function1<void, boost::shared_ptr<RBX::Instance>, std::allocator<void> >
> InstanceSignal1;

// Explicit instantiation of only the connect(slot, at) member (ret 0xc: hidden return, slot, at).
template boost::signals::connection
InstanceSignal1::connect(const InstanceSignal1::slot_type& in_slot,
                         boost::signals::connect_position at);

// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
#include <boost/signal.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

namespace RBX { class Instance; }

// INFERRED: this is the boost::signal1<void, shared_ptr<Instance>>::connect(slot, at)
// instantiation. The 3 stack dwords are: hidden connection return slot, slot, at.
// The hidden return pointer is made explicit so the ABI matches (ret 12, eax = result).
// Vendor body (inlined by /Ob2):
//   if (!in_slot.is_active()) return connection();
//   return impl->connect_slot(in_slot.get_slot_function(), group, in_slot.get_data(), at);
typedef boost::signal1<void, boost::shared_ptr<RBX::Instance> > InstanceSignal;

extern "C" boost::signals::connection* __fastcall fn_005594c0(
    InstanceSignal* self,
    int unusedEdx,
    boost::signals::connection* result,
    const InstanceSignal::slot_type& inSlot,
    boost::signals::connect_position at)
{
    (void)unusedEdx;
    new (result) boost::signals::connection(self->connect(inSlot, at));
    return result;
}

// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header was provided, so this relies on the boost headers being on the include path.
// INFERRED: this is boost::signal1<void, shared_ptr<Instance>>::connect(slot, at), called through a C-linkage wrapper.
// INFERRED: the stack args are (hidden connection return pointer, in_slot, at), which gives ret 12.
#include <new>
#include <boost/signal.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include <functional>

namespace RBX { class Instance; }

typedef boost::signal1<
    void,
    boost::shared_ptr<RBX::Instance>,
    boost::last_value<void>,
    int,
    std::less<int>,
    boost::function<void (boost::shared_ptr<RBX::Instance>)>
> InstanceSignal;

extern "C" boost::signals::connection* __fastcall fn_004b1b00(
    InstanceSignal* self,
    int unusedEdx,
    boost::signals::connection* ret,
    const InstanceSignal::slot_type& in_slot,
    boost::signals::connect_position at)
{
    // INFERRED: the vendor body (is_active check, then impl->connect_slot(get_slot_function(), group,
    // get_data(), at)) is reached through the public connect overload because impl is private.
    // The result is constructed into the caller-supplied hidden return slot.
    new (ret) boost::signals::connection(self->connect(in_slot, at));
    return ret;
}

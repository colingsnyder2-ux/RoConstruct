// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 005dbc70: boost::function1<void,bool,std::allocator<void> > constructor from
// SignalDescImpl<1,void(bool)>::GenericSlotAdapter (signal path, allocator<void>). Evidence: it stores the stored
// vtable 0083d7c4 = {manager 005da1e0 (functor_manager<GenericSlotAdapter<1,void(bool)>, allocator<void> >, typeid
// 00953e08 .?AVGenericSlotAdapter@?$SignalDescImpl@$00$$A6AX_N@Z), invoker 005dab40 -> adapter call 005da420 (one bool
// Value)}. Chain: connectGeneric 005dc920 (slot 1 of the SignalDesc<Humanoid/Lighting/BoolValue, void(bool)> vtables
// 0083d7a0 / 0083ddf0 / 00848b44) -> slot ctor 005dbdb0 -> function ctor 005dbd00 -> 005dbc70. The registry names of
// 005dc920 / 005dbdb0 / 005dbd00 spell SignalDescImpl<2,void(float,float)> (wrong; RTTI above says void(bool)).
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/thread/tss.hpp>
#include "reflection/signal.h"
typedef RBX::Reflection::SignalDescImpl<1,void (bool)>::GenericSlotAdapter F;
template boost::slot<boost::function<void (bool), std::allocator<void> > >::slot(const F&);      // 005dbdb0 -> 005dbd00 -> 005dbc70

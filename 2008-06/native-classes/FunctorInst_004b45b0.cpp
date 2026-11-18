// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 004b45b0: boost machinery instantiated for the functor whose typeid the binary names here (functor_lane.py, no model)
// INFERRED: std::allocator<void> (signal path: caller 004b5050) over the byte-identical [('ctor', 'functionN', 'fb')]
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/thread/tss.hpp>
#include "reflection/signal.h"
typedef RBX::Reflection::SignalDescImpl<0,void (void)>::GenericSlotAdapter F;
template boost::slot<boost::function<void (), std::allocator<void> > >::slot(const F&);      // emits the functionN constructor at 004b45b0 as its callee

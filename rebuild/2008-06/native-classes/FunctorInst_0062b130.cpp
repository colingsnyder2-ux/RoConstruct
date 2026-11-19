// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 0062b130: boost machinery instantiated for the functor whose typeid the binary names here (functor_lane.py, no model)
// INFERRED: std::allocator<void> (signal path: caller 0062b390) over the byte-identical [('ctor', 'functionN', 'fb')]
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/thread/tss.hpp>
#include "reflection/signal.h"
#include "v8tree/Instance.h"
typedef RBX::Reflection::SignalDescImpl<2,void (boost::shared_ptr<RBX::Instance>,float)>::GenericSlotAdapter F;
template boost::slot<boost::function<void (boost::shared_ptr<RBX::Instance>, float), std::allocator<void> > >::slot(const F&);      // emits the functionN constructor at 0062b130 as its callee

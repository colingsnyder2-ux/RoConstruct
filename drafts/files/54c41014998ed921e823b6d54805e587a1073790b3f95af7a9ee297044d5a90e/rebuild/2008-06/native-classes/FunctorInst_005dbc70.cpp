// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 005dbc70: boost::function2<void,float,float,std::allocator<void> > constructor from
// SignalDescImpl<2,void(float,float)>::GenericSlotAdapter. Evidence: its only caller 005dbd00 is the registry's
// boost::function<void(float,float),std::allocator<void> >::function(GenericSlotAdapter<2,void(float,float)>), which
// forwards the adapter (shared_ptr by value) to it; same shape as FunctorInst_0057a870 / FunctorInst_004b45b0.
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/thread/tss.hpp>
#include "reflection/signal.h"
typedef RBX::Reflection::SignalDescImpl<2,void (float,float)>::GenericSlotAdapter F;
template boost::function<void (float, float), std::allocator<void> >::function(F, boost::enable_if_c<(boost::type_traits::ice_not<(boost::is_integral<F>::value)>::value), int>::type);   // 005dbd00, calls the function2 constructor 005dbc70

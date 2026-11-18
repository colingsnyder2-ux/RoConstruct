// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 0049c630: boost machinery instantiated for the functor whose typeid the binary names here (functor_lane.py, no model)
// INFERRED: std::allocator<boost::function_base> (boost default) over the byte-identical [('ctor', 'functionN', 'void')]
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/thread/tss.hpp>
#include "reflection/signal.h"
#include "v8tree/Instance.h"
typedef RBX::Reflection::SignalDescImpl<1,void (boost::shared_ptr<RBX::Instance>)>::GenericSlotAdapter F;
template boost::function1<void, boost::shared_ptr<RBX::Instance>, std::allocator<boost::function_base> >::function1(F, boost::enable_if_c<(boost::type_traits::ice_not<(boost::is_integral<F>::value)>::value), int>::type);

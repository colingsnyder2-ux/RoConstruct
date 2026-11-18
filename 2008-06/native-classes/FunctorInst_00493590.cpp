// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 00493590: boost machinery instantiated for the functor whose typeid the binary names here (functor_lane.py, no model)
// INFERRED: std::allocator<void> (signal path: caller 00493a90) over the byte-identical [('ctor', 'functionN', 'fb')]
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/thread/tss.hpp>
#include "reflection/signal.h"
#include "v8tree/Instance.h"
typedef RBX::Reflection::SignalDescImpl<2,void (std::basic_string<char,std::char_traits<char>,std::allocator<char> >,boost::shared_ptr<RBX::Instance>)>::GenericSlotAdapter F;
template boost::function2<void, std::basic_string<char,std::char_traits<char>,std::allocator<char> >, boost::shared_ptr<RBX::Instance>, std::allocator<void> >::function2(F, boost::enable_if_c<(boost::type_traits::ice_not<(boost::is_integral<F>::value)>::value), int>::type);

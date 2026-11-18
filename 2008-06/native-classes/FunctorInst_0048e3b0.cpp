// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 0048e3b0: boost machinery instantiated for the functor whose typeid the binary names here (functor_lane.py, no model)
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/thread/tss.hpp>
#include "Network/Player.h"
typedef boost::_bi::bind_t<void,boost::_mfi::mf0<void,RBX::Network::Player>,boost::_bi::list1<boost::_bi::value<boost::shared_ptr<RBX::Network::Player> > > > F;
template void boost::function0<void, std::allocator<boost::function_base> >::assign_to<F>(const F&);

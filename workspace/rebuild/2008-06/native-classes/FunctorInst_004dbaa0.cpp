// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 004dbaa0: boost machinery instantiated for the functor whose typeid the binary names here (functor_lane.py, no model)
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/thread/tss.hpp>
#include "ViewG3D2008/ViewG3D2008.h"
typedef boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::ViewNew::ViewG3D,bool>,boost::_bi::list2<boost::_bi::value<RBX::ViewNew::ViewG3D *>,boost::arg<1> > > F;
template boost::slot<boost::function<void (bool), std::allocator<void> > >::slot(const F&);

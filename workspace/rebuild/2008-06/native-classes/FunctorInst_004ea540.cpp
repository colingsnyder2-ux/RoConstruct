// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 004ea540: boost machinery instantiated for the functor whose typeid the binary names here (functor_lane.py, no model)
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/thread/tss.hpp>
#include "ViewNew/PartChunk.h"
typedef boost::_bi::bind_t<void,boost::_mfi::mf0<void,RBX::ViewNew::PartChunk>,boost::_bi::list1<boost::_bi::value<RBX::ViewNew::PartChunk *> > > F;
template boost::slot<boost::function<void (), std::allocator<void> > >::slot(const F&);

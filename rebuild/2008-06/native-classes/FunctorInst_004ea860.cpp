// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 004ea860: boost machinery instantiated for the functor whose typeid the binary names here (functor_lane.py, no model)
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/thread/tss.hpp>
#include "ViewNew/PartChunk.h"
#include "v8tree/Instance.h"
typedef boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::ViewNew::Decal,boost::shared_ptr<RBX::Instance> >,boost::_bi::list2<boost::_bi::value<RBX::ViewNew::Decal *>,boost::arg<1> > > F;
template boost::slot<boost::function<void (boost::shared_ptr<RBX::Instance>), std::allocator<void> > >::slot(const F&);

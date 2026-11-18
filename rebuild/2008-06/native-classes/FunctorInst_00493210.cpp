// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 00493210: boost machinery instantiated for the functor whose typeid the binary names here (functor_lane.py, no model)
// INFERRED: std::allocator<void> (boost default) over the byte-identical [('ctor', 'function', 'fb')]
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/thread/tss.hpp>
#include "util/NativeContentProvider.h"
#include "util/RunStateOwner.h"
#include "v8datamodel/ModelInstance.h"
typedef boost::_bi::bind_t<void,void (*)(boost::shared_ptr<RBX::Instance>,boost::shared_ptr<RBX::RunService>,RBX::ContentProvider::RequestResult,boost::shared_ptr<std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > >),boost::_bi::list4<boost::_bi::value<boost::shared_ptr<RBX::ModelInstance> >,boost::_bi::value<boost::shared_ptr<RBX::RunService> >,boost::arg<1>,boost::arg<2> > > F;
template boost::slot<boost::function<void (RBX::ContentProvider::RequestResult, boost::shared_ptr<std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > >), std::allocator<void> > >::slot(const F&);      // emits the function constructor at 00493210 as its callee

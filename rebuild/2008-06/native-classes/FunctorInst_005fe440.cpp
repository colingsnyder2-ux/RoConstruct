// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 005fe440 (placeholder func_005fe440, 84 B): boost::function1<void, shared_ptr<Instance> >::assign_to for the Tool
// bind_t of boost::bind(&Tool::onEvent_*, this, _1) (onEvent_AddedBackend / onEvent_RemovedBackend / onEvent_HandleTouched,
// one bind type): has_empty_target 0060a2f0, the 0x18-byte functor copied to +8, stored vtable 00841990. Same
// pattern as FunctorInst_0042b8b0.cpp.
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include "v8datamodel/Tool.h"
typedef boost::_bi::bind_t<void,boost::_mfi::mf1<void,RBX::Tool,boost::shared_ptr<RBX::Instance> >,boost::_bi::list2<boost::_bi::value<RBX::Tool *>,boost::arg<1> > > F;
// The slot constructor (callers connectTouchEvent / upTo_InCharacter / upTo_HasTorso) emits the assign_to of
// function1<void, shared_ptr<Instance>, std::allocator<void> > as its callee; that reference tells 005fe440 from its
// byte-identical twins 005a2860 / 005b17d0.
template boost::slot<boost::function<void (boost::shared_ptr<RBX::Instance>), std::allocator<void> > >::slot(const F&);

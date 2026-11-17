// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 2008-06 native boost::function / boost::slot instances of RBX::Instance child-signal binds (inactive):
// function1<void, shared_ptr<Instance>, allocator<void>>::assign_to<bind_t<mf1<void, X, shared_ptr<Instance>>, list2<value<X*>, arg<1>>>>
// and boost::slot<function<void(shared_ptr<Instance>)>>::slot(const bind_t&) for Accoutrement, Tool, Flag and Seat.
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/shared_ptr.hpp>
#include "util/Name.h"
#include "v8datamodel/Accoutrement.h"
#include "v8datamodel/Tool.h"
#include "v8datamodel/Flag.h"
#include "v8datamodel/Seat.h"

typedef boost::shared_ptr<RBX::Instance> InstancePtr;
typedef boost::function1<void, InstancePtr, std::allocator<void> > InstanceFn1;
typedef boost::slot<boost::function<void(InstancePtr)> > InstanceSlot;

#define INST(C) 	typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, RBX::C, InstancePtr>, 		boost::_bi::list2<boost::_bi::value<RBX::C*>, boost::arg<1> > > C##Bind; 	template void InstanceFn1::assign_to<C##Bind>(const C##Bind&); 	template InstanceSlot::slot(const C##Bind&);
INST(Accoutrement)
INST(Tool)
INST(Flag)
INST(Seat)

// retry

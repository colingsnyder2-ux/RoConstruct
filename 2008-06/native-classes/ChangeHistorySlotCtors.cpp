// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-function-pod-vtable
// 2008-06 native boost::slot constructors built by ChangeHistoryService::start 0058c620 (inactive).
// Identity: identity-registry decorated names (owner boost::slot<function<...>>), callers ChangeHistoryService::start
// 0058c620 (Instance::event_descendentAdded / event_itemChanged connects), address range 00588f00..0058ab90 of the
// ChangeHistoryService unit. Both bodies share the slot ctor EH handler 007ca86e with VelocityMotor's 0060b650 slot.
//   0058aa30 slot(const bind_t<void, mf1<void, ChangeHistoryService, shared_ptr<Instance> >, list2<value<this>, _1> >&)
//            -> function<void(shared_ptr<Instance>)>(F, int) 00588f00 out of line (functor in place at +8, ret 0x14).
//   0058aae0 slot(const bind_t<void, mf2<..., shared_ptr<Instance>, const PropertyDescriptor*>, list3<value<this>, _1, _2> >&)
//            -> function<void(shared_ptr<Instance>, const PropertyDescriptor*)>(F, int) 005893b0.
// The binders are the boost::bind(&ChangeHistoryService::onHistoryAdded / onHistoryChanged, this, _1[, _2]) of
// ChangeHistoryStart.cpp; that unit builds without the boost-function-pod-vtable profile, which these two need
// (the same profile makes the matching VelocityMotor slot 0060b650 exact in Feature.cpp).
#include "v8datamodel/ChangeHistoryService.h"
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>

typedef boost::_bi::bind_t<void,
	boost::_mfi::mf1<void, RBX::ChangeHistoryService, boost::shared_ptr<RBX::Instance> >,
	boost::_bi::list2<boost::_bi::value<RBX::ChangeHistoryService*>, boost::arg<1> > > ChangeHistoryInstanceBinder;
typedef boost::_bi::bind_t<void,
	boost::_mfi::mf2<void, RBX::ChangeHistoryService, boost::shared_ptr<RBX::Instance>, const RBX::Reflection::PropertyDescriptor*>,
	boost::_bi::list3<boost::_bi::value<RBX::ChangeHistoryService*>, boost::arg<1>, boost::arg<2> > > ChangeHistoryChangedBinder;

// 0058aa30
template boost::slot<boost::function<void(boost::shared_ptr<RBX::Instance>)> >::slot(const ChangeHistoryInstanceBinder&);
// 0058aae0
template boost::slot<boost::function<void(boost::shared_ptr<RBX::Instance>, const RBX::Reflection::PropertyDescriptor*)> >::slot(
	const ChangeHistoryChangedBinder&);

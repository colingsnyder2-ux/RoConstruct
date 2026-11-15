// 2008-06 native rows of the Creatable / FactoryProduct instances inside the application range 0040c000..00418000
// outside the metadata block (inactive). Verified by tests/record_native_app_unit40c_2008.py. All headers are
// read-only here.
//
// Two runs of compiler-emitted template instances, each class with, in link order:
//   * boost::detail::shared_count(C*, Creatable<Instance>::Deleter) (131 B; counted by creatable-shared-count);
//   * boost::shared_ptr<C>(C*, Creatable<Instance>::Deleter) (171 B, the enable_shared_from_this hook-up);
//   * Creatable<Instance>::create<C>() (120 / 122 B: malloc(sizeof(C)), C(), shared_ptr<C>(p, Deleter()));
//   * FactoryProduct<C, D, N>::Creator::create() const (175 B, slot 0 of the Creator vtable), where C is creatable.
// The chat run 00411d90..0041202f (ChatEnter, Network::Players; the CChatPrompt unit creates both) and the clipboard-verb
// run 00414820..004151ff (ModelInstance, Script, LocalScript, ChangeHistoryService; Creator vtables 0080e9ac /
// 0080e9c8 / 0080e9e4 / 0080ea00). sizeof(C) comes from the native headers and is checked against the malloc size.
#include "ChatEnter.h"
#include "Network/Players.h"
#include "v8datamodel/ModelInstance.h"
#include "script/Script.h"
#include "v8datamodel/ChangeHistoryService.h"
#include "util/Object.h"

namespace RBX
{
	// util/Object.h declares Creator::create() only; this is the definition every Creator vtable slot 0 reaches.
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}
}

template boost::shared_ptr<ChatEnter> RBX::Creatable<RBX::Instance>::create<ChatEnter>();
template boost::shared_ptr<RBX::Network::Players> RBX::Creatable<RBX::Instance>::create<RBX::Network::Players>();
template boost::shared_ptr<RBX::ModelInstance> RBX::Creatable<RBX::Instance>::create<RBX::ModelInstance>();
template boost::shared_ptr<RBX::Script> RBX::Creatable<RBX::Instance>::create<RBX::Script>();
template boost::shared_ptr<RBX::LocalScript> RBX::Creatable<RBX::Instance>::create<RBX::LocalScript>();
template boost::shared_ptr<RBX::ChangeHistoryService> RBX::Creatable<RBX::Instance>::create<RBX::ChangeHistoryService>();

template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::ModelInstance, RBX::PVInstance, RBX::sModel>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Script, RBX::Instance, RBX::sScript>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::LocalScript, RBX::Script, RBX::sLocalScript>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::ChangeHistoryService, RBX::Instance, RBX::sChangeHistoryService>::Creator::create() const;

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<ChatEnter>;
template class boost::shared_ptr<RBX::LocalScript>;
template class boost::shared_ptr<RBX::Network::Players>;
template class boost::shared_ptr<RBX::Script>;

// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/engine-world
// 2008-06 native RBX::PhysicsService (inactive); evidence in native-headers/v8datamodel/PhysicsService.h.
// Unsplit/combined: includes onEvent bodies and service find/create (mew 5fe2214 integration, native-doc link).
// >>> native-status (generated) -- do not edit >>>
// PhysicsService | 2008-06 | 4 byte-exact, inactive (not link-selected)
// 4/5 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (+2) (mixed 4)
// <<< native-status | src dd9d9405 | roc native-status --write
#include "engine-world/v8world/World.h"
#include "v8datamodel/PhysicsService.h"
#include "v8datamodel/PartInstance.h"
#include "reflection/signal.h"
#include "v8tree/Service.h"
#include <boost/thread/once.hpp>

namespace RBX
{
	const char sPhysicsService[] = "PhysicsService"; // 0083f858

	// Template members the shared headers only declare.
	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::className() { return Name::declare<N>(); }

	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::getClassName() const { return className(); }

	// Dynamic initializers 007f6e40, 007f6e60 (atexit 007ffa50 / 007ffa10 region).
	static Reflection::SignalDesc<PhysicsService, void(boost::shared_ptr<Instance>)> event_AssemblyAdded("AssemblyAdded", "part");
	static Reflection::SignalDesc<PhysicsService, void(boost::shared_ptr<Instance>)> event_AssemblyRemoved("AssemblyRemoved", "part");

	PhysicsService::~PhysicsService()
	{
	}

	void PhysicsService::onAdded(PartInstance* part)
	{
		event_AssemblyAdded.fire(this, shared_from(part));
		// The named result keeps the original 0x18-byte frame (a discarded insert result uses 0x10).
		std::pair<std::set<PartInstance*>::iterator, bool> result = parts.insert(part);
	}

	void PhysicsService::onRemoved(PartInstance* part)
	{
		parts.erase(part);
		event_AssemblyRemoved.fire(this, shared_from(part));
	}

	void PhysicsService::onEvent(const World* source, AssemblyPhysicsOn event)
	{
		onAdded(PartInstance::fromPrimitive(event.primitive));
	}

	void PhysicsService::onEvent(const World* source, AssemblyPhysicsOff event)
	{
		onRemoved(PartInstance::fromPrimitive(event.primitive));
	}

	// ServiceProvider find/create support (unsplit from PhysicsServiceFind/Allocation; pattern adapted)
	template<class Class> size_t ServiceProvider::doGetClassIndex() {
		static size_t index = newIndex();
		return index;
	}
	template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
	template<class Class> size_t ServiceProvider::getClassIndex() {
		static boost::once_flag flag = BOOST_ONCE_INIT;
		boost::call_once(&callDoGetClassIndex<Class>, flag);
		return doGetClassIndex<Class>();
	}
	template<> PhysicsService* ServiceProvider::find<PhysicsService>() const {
		size_t index = getClassIndex<PhysicsService>();
		if (index + 1 > serviceArray.size()) {
			serviceArray.resize(index + 1, boost::shared_ptr<Instance>());
		} else {
			PhysicsService* service = static_cast<PhysicsService*>(serviceArray[index].get());
			if (service) return service;
		}
		boost::shared_ptr<Instance> item = findServiceByClassName(PhysicsService::className());
		if (!item) return NULL;
		serviceArray[index] = item;
		return static_cast<PhysicsService*>(item.get());
	}
	template boost::shared_ptr<PhysicsService> Creatable<Instance>::create<PhysicsService>();
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::PartInstance *> >;
template class std::_Tree<std::_Tset_traits<RBX::PartInstance *,std::less<RBX::PartInstance *>,std::allocator<RBX::PartInstance *>,0> >;
template class std::allocator<RBX::PartInstance *>;
template class std::allocator<std::_Tree_nod<std::_Tset_traits<RBX::PartInstance *,std::less<RBX::PartInstance *>,std::allocator<RBX::PartInstance *>,0> >::_Node *>;
template class std::pair<std::_Tree<std::_Tset_traits<RBX::PartInstance *,std::less<RBX::PartInstance *>,std::allocator<RBX::PartInstance *>,0> >::iterator,std::_Tree<std::_Tset_traits<RBX::PartInstance *,std::less<RBX::PartInstance *>,std::allocator<RBX::PartInstance *>,0> >::iterator>;

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sPhysicsService>();

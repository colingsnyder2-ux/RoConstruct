#include <cstddef>

namespace RBX {
namespace RenderBase {
// INFERRED: free function 00553f90 (AggregateChunk) used by 007f2bd0.
int AggregateChunk(const char* name, int size);
}
}

void func_007f2bd0()
{
    *(volatile int*)0x00973ec4 = RBX::RenderBase::AggregateChunk((const char*)0x0080f7cc, 0xbb8);
}

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

	Reflection::SignalDesc<PhysicsService, void(boost::shared_ptr<Instance>)> PhysicsService::eventAdded("AssemblyAdded", "part");
	Reflection::SignalDesc<PhysicsService, void(boost::shared_ptr<Instance>)> PhysicsService::eventRemoved("AssemblyRemoved", "part");

	PhysicsService::~PhysicsService()
	{
	}

	void PhysicsService::onAdded(PartInstance* part)
	{
		eventAdded.fire(this, shared_from(part));
		// The named result keeps the original 0x18-byte frame (a discarded insert result uses 0x10).
		std::pair<std::set<PartInstance*>::iterator, bool> result = parts.insert(part);
	}

	void PhysicsService::onRemoved(PartInstance* part)
	{
		parts.erase(part);
		eventRemoved.fire(this, shared_from(part));
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

template class std::_Container_base_aux_alloc_real<std::allocator<RBX::PartInstance *> >;
template class std::_Tree<std::_Tset_traits<RBX::PartInstance *,std::less<RBX::PartInstance *>,std::allocator<RBX::PartInstance *>,0> >;
template class std::allocator<RBX::PartInstance *>;
template class std::allocator<std::_Tree_nod<std::_Tset_traits<RBX::PartInstance *,std::less<RBX::PartInstance *>,std::allocator<RBX::PartInstance *>,0> >::_Node *>;
template class std::pair<std::_Tree<std::_Tset_traits<RBX::PartInstance *,std::less<RBX::PartInstance *>,std::allocator<RBX::PartInstance *>,0> >::iterator,std::_Tree<std::_Tset_traits<RBX::PartInstance *,std::less<RBX::PartInstance *>,std::allocator<RBX::PartInstance *>,0> >::iterator>;

template void RBX::Name::callDoDeclare<RBX::sPhysicsService>();

#include "util/Name.h"
#include "util/Debug.h"

// intentionally outside of the RBX namespace
boost::once_flag flag = BOOST_ONCE_INIT;

boost::mutex& moo2()
{
	static boost::mutex mutex2;
	return mutex2;
}

void initMoo()
{
	moo2();
}

static const RBX::Name* nullName;
static void initNullName()
{
    nullName = &RBX::Name::declare("", 0);
}

namespace RBX
{
	// seems to be inlined
	boost::mutex& Name::mutex()
	{
		boost::call_once(initMoo, flag);
		return moo2();
	}

	std::map<int, Name*>& Name::dictionary()
	{
		static std::map<int, Name*> d;
		return d;
	}

	Name::NamMap& Name::namMap()
	{
		static NamMap n;
		return n;
	}

	const Name& Name::getNullName()
	{
        static boost::once_flag nullNameFlag = BOOST_ONCE_INIT;
        boost::call_once(initNullName, nullNameFlag);
        return *nullName;
    }

	const Name& Name::declare(const char* sName, int dictionaryIndex)
	{
		if (!sName)
		{
			return getNullName();
		}

		boost::mutex::scoped_lock scoped_lock(mutex());

		NamMap::iterator iter = namMap().find(std::string(sName));
		if (iter != namMap().end())
		{
			if (dictionaryIndex != -1)
			{
				iter->second->dictionaryIndex = dictionaryIndex;
				dictionary()[dictionaryIndex] = iter->second;
			}
			return *iter->second;
		}
		else
		{
			Name* name = new Name(sName, dictionaryIndex);
			namMap()[sName] = name;
			dictionary()[dictionaryIndex] = name;
			return *name;
		}
	}

	const Name& Name::lookup(const std::string& sName)
	{
		                            ;
		boost::mutex::scoped_lock scoped_lock(mutex());

		NamMap::iterator iter = namMap().find(sName);
		if (iter != namMap().end())
		{
			return *iter->second;
		}
		else
		{
			return getNullName();
		}
	}

	const Name& Name::lookup(const char* sName)
	{
		if (!sName)
		{
			return getNullName();
		}

		return lookup(std::string(sName));
	}
}

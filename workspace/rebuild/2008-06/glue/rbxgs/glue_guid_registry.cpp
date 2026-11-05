// Rebuild glue: instance references over the network. rbxgs serializes an instance as its Guid::Data
// (IdSerializer::serializeId) but has nothing that maps the id back to the instance. The 2008 client
// keeps such a registry (GuidItem<Instance> carries a registeredGuid flag); this is a behavioural
// reconstruction: ids are registered when sent (overlay patch in Streaming.cpp) or received
// (glue_replicator.cpp), held weakly, and looked up when a reference is read. Not byte-verified.
#include <RakPeer.h>  // first, as rbxgs Players.cpp: RakNet needs winsock2 before windows.h
#include <BitStream.h>
#include "Streaming.h"
#include "reflection/property.h"
#include <boost/thread/mutex.hpp>
#include <boost/weak_ptr.hpp>
#include <map>

namespace RBX
{
	namespace Network
	{
		namespace
		{
			boost::mutex& registryMutex()
			{
				static boost::mutex m;
				return m;
			}

			std::map<Guid::Data, boost::weak_ptr<Instance> >& registry()
			{
				static std::map<Guid::Data, boost::weak_ptr<Instance> > r;
				return r;
			}
		}

		void rebuildRegisterGuid(const Instance* instance)
		{
			if (!instance)
				return;
			Guid::Data id;
			instance->getGuid().extract(id);
			boost::mutex::scoped_lock lock(registryMutex());
			registry()[id] = shared_from(const_cast<Instance*>(instance));
		}

		Instance* rebuildFindGuid(const Guid::Data& id)
		{
			boost::mutex::scoped_lock lock(registryMutex());
			std::map<Guid::Data, boost::weak_ptr<Instance> >::iterator iter = registry().find(id);
			if (iter == registry().end())
				return NULL;
			boost::shared_ptr<Instance> instance = iter->second.lock();
			if (!instance)
				registry().erase(iter);
			return instance.get();
		}

		// true when the reference is resolved now (a null reference counts as resolved)
		bool IdSerializer::deserializeInstanceRef(RakNet::BitStream& stream, Instance*& instance, Guid::Data& id)
		{
			deserializeId(stream, id);
			if (*id.scope == Name::getNullName())
			{
				instance = NULL;
				return true;
			}
			instance = rebuildFindGuid(id);
			return instance != NULL;
		}

		bool IdSerializer::deserializeInstanceRef(RakNet::BitStream& stream, Instance*& instance)
		{
			Guid::Data id;
			return deserializeInstanceRef(stream, instance, id);
		}

		// an unknown target waits until that instance arrives (resolvePendingBindings)
		void IdSerializer::deserializeRef(Reflection::Property& property, RakNet::BitStream& stream)
		{
			const Reflection::RefPropertyDescriptor& desc = static_cast<const Reflection::RefPropertyDescriptor&>(property.getDescriptor());
			Instance* target = NULL;
			Guid::Data id;
			if (deserializeInstanceRef(stream, target, id))
			{
				desc.setRefValue(property.getInstance(), target);
				return;
			}
			WaitItem item;
			item.desc = &desc;
			item.instance = shared_from(static_cast<Instance*>(property.getInstance()));
			waitItems[id].push_back(item);
		}
	}
}

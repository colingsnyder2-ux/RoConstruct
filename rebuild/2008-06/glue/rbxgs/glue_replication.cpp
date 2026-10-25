// Rebuild glue: Replicator's replication-scope hookup, which rbxgs declares but never defines
// (replicationContainers was never filled, so nothing replicated). The containers are the services
// whose subtrees replicate in 2008 (Workspace, Lighting, Players, Teams, StarterPack). Descendants
// added under them queue a NewInstanceItem and get a property-changed connection; descendants removed
// queue a DeleteInstanceItem unless their creation was still pending. Behavioural reconstruction in
// rbxgs's item model, not byte-verified.
#include <RakPeer.h>
#include "Replicator.h"
#include "Network/Players.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Lighting.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/Hopper.h"

namespace RBX
{
	namespace Network
	{
		Replicator::DeleteInstanceItem::DeleteInstanceItem(Replicator& replicator, const boost::shared_ptr<const Instance>& instance)
			: Item(replicator), instance(instance)
		{
		}

		void Replicator::connectToReplicationContainers()
		{
			Instance* containers[] = {
				ServiceProvider::find<Workspace>(this),
				ServiceProvider::find<Lighting>(this),
				ServiceProvider::find<Players>(this),
				ServiceProvider::find<Teams>(this),
				ServiceProvider::find<StarterPackService>(this),
			};

			for (size_t i = 0; i < sizeof(containers) / sizeof(containers[0]); ++i)
			{
				Instance* container = containers[i];
				if (!container || std::find(replicationContainers.begin(), replicationContainers.end(), container) != replicationContainers.end())
					continue;

				replicationContainers.push_back(container);
				replicationContainerConnections.push_back(Instance::event_descendentAdded.connect(container, boost::bind(&Replicator::onDescendentAdded, this, _1)));
				replicationContainerConnections.push_back(Instance::event_descendentRemoving.connect(container, boost::bind(&Replicator::onDescendentRemoving, this, _1)));
				container->visitDescendents(boost::bind(&Replicator::onDescendentAdded, this, _1));
			}
		}

		void Replicator::onDescendentAdded(boost::shared_ptr<Instance> instance)
		{
			if (!wantReplicate(instance.get()) || getCameFromRemotePlayer(instance.get()))
			{
				connectPropertyChanged(instance);
				return;
			}

			if (pendingDeleteInstances.erase(instance.get()) == 0)
			{
				pendingNewInstances.insert(instance.get());
				pendingItems.push_back(boost::shared_ptr<Item>(new NewInstanceItem(*this, instance)));
			}
			connectPropertyChanged(instance);
		}

		void Replicator::onDescendentRemoving(boost::shared_ptr<Instance> instance)
		{
			disconnectPropertyChanged(instance);

			if (!wantReplicate(instance.get()))
				return;

			// never sent: dropping the pending creation is enough
			if (pendingNewInstances.erase(instance.get()) == 0)
			{
				pendingDeleteInstances.insert(instance.get());
				pendingItems.push_back(boost::shared_ptr<Item>(new DeleteInstanceItem(*this, instance)));
			}
		}

		void Replicator::connectPropertyChanged(boost::shared_ptr<Instance> instance)
		{
			if (propertyChangedConnections.find(instance) != propertyChangedConnections.end())
				return;
			propertyChangedConnections[instance] = Instance::event_propertyChanged.connect(instance.get(), boost::bind(&Replicator::onPropertyChanged, this, instance, _1));
		}
	}
}

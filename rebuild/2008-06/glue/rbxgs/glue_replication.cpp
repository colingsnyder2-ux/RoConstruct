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

	}
}

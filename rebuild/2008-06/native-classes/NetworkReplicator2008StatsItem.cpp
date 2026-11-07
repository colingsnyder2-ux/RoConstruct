// 2008-06 native RBX::Network::Replicator::ReplicatorStatsItem rows that do not depend on the (partial) Replicator
// layout (inactive); evidence in native-headers/Network/Replicator2008.h. Verified by
// tests/record_native_network_replicator2008.py. Original bodies: Creatable<Instance>::create<ReplicatorStatsItem,
// shared_ptr<Replicator>, RakNetStatistics*> 004b7e50 (Replicator::createStatsItems 004b82d0 calls it) and
// shared_ptr<ReplicatorStatsItem>(ReplicatorStatsItem*, Creatable<Instance>::Deleter) 004acf50. The constructor
// 004b62c0 and update 004b6530 read Replicator members past +0x2b90 and stay open; the implicit destructor 004b6690,
// deleting destructor 004b6710 and its thunks are only emitted with the constructor's vtable.
#include "Network/Replicator2008.h"

namespace RBX
{
	template boost::shared_ptr<Network::Replicator::ReplicatorStatsItem>
	Creatable<Instance>::create<Network::Replicator::ReplicatorStatsItem, boost::shared_ptr<Network::Replicator>,
								RakNetStatistics*>(boost::shared_ptr<Network::Replicator>, RakNetStatistics*); // 004b7e50
}

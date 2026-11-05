// 2008-06 native RBX::Network::PhysicsSender / InterpolatingPhysicsReceiver (inactive); evidence in
// native-headers/Network/PhysicsSenders2008.h. Verified by tests/record_native_network_physics_senders2008.py.
// Rows compiled here: the two constructors, PhysicsSender's destructor and both scalar deleting destructors, plus the
// boost 1.34.1 multi_index_container instantiations they reach (container constructors/destructors, hashed index
// constructor, bucket array constructor, max-load calculation, ordered empty_initialize, delete_all_nodes and the
// compiler-generated PartItem/History destructors). step/sendPackets/receivePacket are declared only (open: they
// need the native Replicator). Built with /fp:fast (calculate_max_load 004ca090 keeps the product on the x87 stack).
#include "Network/PhysicsSenders2008.h"

namespace RBX
{
	namespace Network
	{
		PhysicsSender::PhysicsSender(Replicator* replicator)
			: replicator(replicator)
			, stepCount(0)
		{
		}

		PhysicsSender::~PhysicsSender()
		{
		}

		InterpolatingPhysicsReceiver::InterpolatingPhysicsReceiver(Replicator* replicator)
			: replicator(replicator)
		{
		}
	}
}

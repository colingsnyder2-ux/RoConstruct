// 2008-06 native RBX::Network::PhysicsSender / InterpolatingPhysicsReceiver (inactive); evidence in
// native-headers/Network/PhysicsSenders2008.h. Verified by tests/record_native_network_physics_senders2008.py.
// Rows compiled here: the out-of-line part hash hash_value 004ca5b0, the two constructors, PhysicsSender's destructor
// and both scalar deleting destructors, plus the boost 1.34.1 multi_index_container instantiations they reach
// (container constructors/destructors, hashed index constructor, bucket array constructor, max-load calculation,
// ordered empty_initialize, delete_all_nodes and the compiler-generated PartItem/History destructors) and, from the
// explicit sender container instantiation below, the sender index members 004c9b20..004cc580. step/sendPackets/
// receivePacket are declared only (open: they need the native Replicator). Built with /fp:fast (calculate_max_load
// 004ca090 keeps the product on the x87 stack).
#include "Network/PhysicsSenders2008.h"

namespace RBX
{
	// 004ca5b0 (cdecl; `mov eax,[esp+4]; mov ecx,[eax]; mov eax,ecx; shr eax,3; add eax,ecx; ret`). Inlined in the
	// sender's own index code (replace_ 004cc5e0 at 004cc64f); the receiver calls this copy.
	std::size_t hash_value(const boost::shared_ptr<PartInstance>& part)
	{
		return boost::hash<PartInstance*>()(part.get());
	}

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

// The sender container's remaining index members (explicit instantiation, as AppUnit4BC_2008Receiver.cpp does for the
// receiver container): the hashed / ordered link, link_point, in_place, insert_, erase_, replace_ and reserve bodies
// and the PartItem copy / assignment the sender's step / sendPackets reach (004c9b20..004cc580).
template class boost::multi_index::multi_index_container<
	RBX::Network::PhysicsSender::PartItem,
	RBX::Network::PhysicsSender::PartItems::index_specifier_type_list>;

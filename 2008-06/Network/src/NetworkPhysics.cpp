// 2008-06 native RBX::Network physics sender/receiver classes (inactive); evidence in
// native-headers/Network/PhysicsReplication.h. Verified by tests/record_native_network_physics.py.
// Rows compiled here: RoundRobinPhysicsSender constructor 004c99c0, its scalar deleting destructor 004ca010, the
// empty step() 0047d410 (identical-code folded), the out-of-line inline ~MechanismTracker 004c99b0;
// DirectPhysicsReceiver scalar deleting destructor 004ab5b0 and the empty step(unsigned) 0070bdf0 (both folded).
// sendPackets 004cd420 and receivePacket 004c83b0 are declared only (open).
// >>> native-status (generated) -- do not edit >>>
// NetworkPhysics | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src b4a7a546 | roc native-status --write
#include "Network/PhysicsReplication.h"

namespace RBX
{
	namespace Network
	{
		RoundRobinPhysicsSender::RoundRobinPhysicsSender(Replicator* replicator)
			: replicator(replicator)
			, lastSendTime(G3D::System::time())
		{
		}

		void RoundRobinPhysicsSender::step()
		{
		}

		void DirectPhysicsReceiver::step(unsigned int)
		{
		}

		// DirectPhysicsReceiver's constructor is inline (the Replicator constructor 004ba117 expands it). The
		// Replicator is not recovered natively, so this non-original helper expands the same `new` to make this unit
		// emit the DirectPhysicsReceiver vtable and scalar deleting destructor: a codegen analog, not the original unit.
		IPhysicsReceiver* nativeNetworkPhysicsNewDirectReceiver(Replicator* replicator)
		{
			return new DirectPhysicsReceiver(replicator);
		}
	}
}

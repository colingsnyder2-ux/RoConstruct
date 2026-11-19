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

		IPhysicsReceiver* nativeNetworkPhysicsNewDirectReceiver(Replicator* replicator)
		{
			return new DirectPhysicsReceiver(replicator);
		}
	}
}

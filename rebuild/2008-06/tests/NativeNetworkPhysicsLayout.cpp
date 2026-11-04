// Layout probe for the inactive native Network physics sender/receiver header;
// tests/record_native_network_physics.py checks each function body is `mov eax, imm32; ret` with the value from the
// binary:
//   sizeof(DirectPhysicsReceiver) 8          Replicator 004ba117 news 8
//   sizeof(RoundRobinPhysicsSender) 0x18     Replicator 004ba073 news 0x18
// Field offsets are compile-time asserts (NativeNetworkPhysicsLayout is a friend of each class): constructor stores
// (004ba12b replicator +4; 004c99c0 replicator +4, tracker +8, lastSendTime +0x10). Built with only native headers
// (plus the donor include dirs every native unit uses).
#include <stddef.h>
#include "Network/PhysicsReplication.h"

struct NativeNetworkPhysicsLayout
{
	typedef RBX::Network::DirectPhysicsReceiver D;
	typedef RBX::Network::RoundRobinPhysicsSender R;
	typedef char DirectReplicator[offsetof(D, replicator) == 0x4 ? 1 : -1];
	typedef char RoundRobinReplicator[offsetof(R, replicator) == 0x4 ? 1 : -1];
	typedef char RoundRobinTracker[offsetof(R, tracker) == 0x8 ? 1 : -1];
	typedef char RoundRobinLastSendTime[offsetof(R, lastSendTime) == 0x10 ? 1 : -1];
	typedef char TrackerSize[sizeof(RBX::MechanismTracker) == 0x4 ? 1 : -1];
};

int nativeDirectPhysicsReceiverSize() { return sizeof(RBX::Network::DirectPhysicsReceiver); }
int nativeRoundRobinPhysicsSenderSize() { return sizeof(RBX::Network::RoundRobinPhysicsSender); }

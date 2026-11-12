// Layout probe for native-headers/Network/PhysicsSenders2008.h (inactive);
// tests/record_native_network_physics_senders2008.py checks each function body is `mov eax, imm32; ret` with the
// value from the binary:
//   sizeof(PhysicsSender) 0x74                    Replicator 004ba094 news 0x74
//   sizeof(InterpolatingPhysicsReceiver) 0x3c     Replicator 004ba0e8 news 0x3c
//   sender node 0x78, receiver node 0x298         header node allocations 004cc419 / 004b0afb
// Field offsets are compile-time asserts (NativeNetworkPhysicsSendersLayout is a friend of both classes), read from
// the constructor stores (004ccb10, 004b5e80), the destructors (004ccb90, 004ccab0, 004b58f0) and the item copy /
// destroy code (004c9d90, 004cc460, 004af950, 004ae910) cited in the header.
#include <stddef.h>
#include "Network/PhysicsSenders2008.h"

struct NativeNetworkPhysicsSendersLayout
{
	typedef RBX::Network::PhysicsSender S;
	typedef RBX::Network::InterpolatingPhysicsReceiver R;
	typedef S::PartItem SI;
	typedef R::PartItem RI;
	typedef R::History H;
	typedef char SenderItems[offsetof(S, items) == 0x4 ? 1 : -1];
	typedef char SenderItemsSize[sizeof(S::PartItems) == 0x34 ? 1 : -1];
	typedef char SenderNextItem[offsetof(S, nextItem) == 0x38 ? 1 : -1];
	typedef char SenderReplicator[offsetof(S, replicator) == 0x3c ? 1 : -1];
	typedef char SenderStepCount[offsetof(S, stepCount) == 0x40 ? 1 : -1];
	typedef char SenderPhysicsService[offsetof(S, physicsService) == 0x44 ? 1 : -1];
	typedef char SenderAdded[offsetof(S, partAddedConnection) == 0x4c ? 1 : -1];
	typedef char SenderSecondConnection[offsetof(S, secondConnection) == 0x60 ? 1 : -1];
	typedef char ConnectionSize[sizeof(boost::signals::scoped_connection) == 0x14 ? 1 : -1];
	typedef char SenderItemSize[sizeof(SI) == 0x50 ? 1 : -1];
	typedef char SenderItemPriority[offsetof(SI, priority) == 0x8 ? 1 : -1];
	typedef char SenderItemFrame[offsetof(SI, lastFrame) == 0x10 ? 1 : -1];
	typedef char SenderItemAccumulated[offsetof(SI, accumulated) == 0x40 ? 1 : -1];
	typedef char SenderItemStep[offsetof(SI, lastSendStep) == 0x44 ? 1 : -1];
	typedef char SenderItemError[offsetof(SI, error) == 0x48 ? 1 : -1];
	typedef char ReceiverReplicator[offsetof(R, replicator) == 0x4 ? 1 : -1];
	typedef char ReceiverItems[offsetof(R, items) == 0x8 ? 1 : -1];
	typedef char ReceiverItemsSize[sizeof(R::PartItems) == 0x34 ? 1 : -1];
	typedef char ReceiverItemSize[sizeof(RI) == 0x280 ? 1 : -1];
	typedef char ReceiverItemTimestamp[offsetof(RI, timestamp) == 0x8 ? 1 : -1];
	typedef char ReceiverItemInterval[offsetof(RI, interval) == 0x10 ? 1 : -1];
	typedef char ReceiverItemHead[offsetof(RI, head) == 0x18 ? 1 : -1];
	typedef char ReceiverItemCount[offsetof(RI, count) == 0x1c ? 1 : -1];
	typedef char ReceiverItemHistory[offsetof(RI, history) == 0x20 ? 1 : -1];
	typedef char HistorySize[sizeof(H) == 0x4c ? 1 : -1];
	typedef char HistoryFrame[offsetof(H, frame) == 0x4 ? 1 : -1];
	typedef char HistoryMotorAngles[offsetof(H, motorAngles) == 0x34 ? 1 : -1];
};

int nativePhysicsSenderSize() { return sizeof(RBX::Network::PhysicsSender); }
int nativeInterpolatingPhysicsReceiverSize() { return sizeof(RBX::Network::InterpolatingPhysicsReceiver); }
int nativePhysicsSenderNodeSize() { return sizeof(RBX::Network::PhysicsSender::PartItems::node_type); }
int nativeInterpolatingPhysicsReceiverNodeSize()
{
	return sizeof(RBX::Network::InterpolatingPhysicsReceiver::PartItems::node_type);
}

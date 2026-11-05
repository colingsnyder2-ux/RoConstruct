// Layout and instantiation probe for the inactive native JointsService / PhysicsService / NetworkSettings headers.
// tests/record_native_services.py checks each size function is `mov eax, imm32; ret` with the allocation size the
// binary passes to malloc, and compares the instantiated creators (and the inline constructors, destructors and
// thunks they emit) with the original:
//   sizeof(JointsService)   0x154  Creatable<Instance>::create<JointsService> 004b0df0
//   sizeof(PhysicsService)  0x158  Creatable<Instance>::create<PhysicsService> 004cd760
//   sizeof(NetworkSettings) 0x160  Creatable<Instance>::create<NetworkSettings> 0049e810
// Field offsets are compile-time asserts (NativeServicesLayout is a friend of each class).
#include <stddef.h>
#include "v8datamodel/JointsService.h"
#include "v8datamodel/PhysicsService.h"
#include "Network/NetworkSettings.h"

struct NativeServicesLayout
{
	typedef char JointsWorld[offsetof(RBX::JointsService, world) == 0x150 ? 1 : -1];
	typedef char PhysicsParts[offsetof(RBX::PhysicsService, parts) == 0x138 ? 1 : -1];
	typedef char NetPrintPhysicsErrors[offsetof(RBX::NetworkSettings, printPhysicsErrors) == 0x130 ? 1 : -1];
	typedef char NetPrintPacketBuffer[offsetof(RBX::NetworkSettings, printPacketBuffer) == 0x133 ? 1 : -1];
	typedef char NetPhysicsSend[offsetof(RBX::NetworkSettings, physicsSendMethod) == 0x134 ? 1 : -1];
	typedef char NetPhysicsReceive[offsetof(RBX::NetworkSettings, physicsReceiveMethod) == 0x138 ? 1 : -1];
	typedef char NetUpdateRate[offsetof(RBX::NetworkSettings, physicsReplicationUpdateRate) == 0x13c ? 1 : -1];
	typedef char NetTest1[offsetof(RBX::NetworkSettings, test1) == 0x140 ? 1 : -1];
	typedef char NetTest4[offsetof(RBX::NetworkSettings, test4) == 0x143 ? 1 : -1];
	typedef char NetPhysicsMtu[offsetof(RBX::NetworkSettings, physicsMtuAdjust) == 0x144 ? 1 : -1];
	typedef char NetReplicationMtu[offsetof(RBX::NetworkSettings, replicationMtuAdjust) == 0x148 ? 1 : -1];
	typedef char NetMaxSendBuffer[offsetof(RBX::NetworkSettings, maxSendBuffer) == 0x14c ? 1 : -1];
	typedef char NetSendRate[offsetof(RBX::NetworkSettings, sendRate) == 0x150 ? 1 : -1];
	typedef char NetMaxSendBPS[offsetof(RBX::NetworkSettings, maxSendBPS) == 0x154 ? 1 : -1];
	typedef char NetMinExtraPing[offsetof(RBX::NetworkSettings, minExtraPing) == 0x158 ? 1 : -1];
	typedef char NetExtraPingVariance[offsetof(RBX::NetworkSettings, extraPingVariance) == 0x15c ? 1 : -1];
};

size_t nativeJointsServiceSize() { return sizeof(RBX::JointsService); }
size_t nativePhysicsServiceSize() { return sizeof(RBX::PhysicsService); }
size_t nativeNetworkSettingsSize() { return sizeof(RBX::NetworkSettings); }

// The original emits these creators in the units that first create each service (ServiceProvider::create).
template boost::shared_ptr<RBX::JointsService> RBX::Creatable<RBX::Instance>::create<RBX::JointsService>();
template boost::shared_ptr<RBX::PhysicsService> RBX::Creatable<RBX::Instance>::create<RBX::PhysicsService>();
template boost::shared_ptr<RBX::NetworkSettings> RBX::Creatable<RBX::Instance>::create<RBX::NetworkSettings>();

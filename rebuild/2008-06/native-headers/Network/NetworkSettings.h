#pragma once
// >>> native-status (generated) -- do not edit >>>
// NetworkSettings | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 7d809577 | roc native-status --write
// 2008-06 native RBX::NetworkSettings (inactive). Shape after the donor tools/rbxgs Client/Network/NetworkSettings.h;
// every base, field and descriptor below is read from the 2008-06 binary:
//   RTTI       vtable 00824344 .?AVNetworkSettings@RBX@@ -> GlobalSettingsItem<NetworkSettings, sNetworkSettings>
//              (vtable 00824074) -> DescribedCreatable<NetworkSettings, GlobalSettings::Item, sNetworkSettings>, and
//              the empty Service (mdisp 0x130). sNetworkSettings is mangled $1?sNetworkSettings@2@3QBDB: a const char
//              array in .rdata at 00823ec0 holding "NetworkSettings" (GlobalSettingsItem constructor 004aa8a0).
//   size       0x160: Creatable<Instance>::create<NetworkSettings> 0049e810 allocates 0x160 and calls the constructor
//              004aabc0, which stores the fields below in declaration order (sendRate first: x87 load of 90.0f from
//              0082438c) and calls setName("Network") (string 00824384).
//   fields     from the constructor and the property initializers 007f1df0..007f2140 (member offsets pushed):
//              +0x130..+0x133 PrintPhysicsErrors, PrintInstances, PrintProperties, PrintPacketBuffer (bool, 0);
//              +0x134 PhysicsSend (PhysicsSendMethod, 0), +0x138 PhysicsReceive (PhysicsReceiveMethod, 1);
//              +0x13c PhysicsReplicationUpdateRate (int, 3000); +0x140..+0x143 Test1..Test4 (bool, 0);
//              +0x144 PhysicsMtuAdjust (int, -80); +0x148 ReplicationMtuAdjust (int, -200); +0x14c MaxSendBuffer
//              (int, 1); +0x150 SendRate (float, 90); +0x154 MaxSendBPS, +0x158 MinExtraPing, +0x15c
//              ExtraPingVariance (int, 0).
//   enums      EnumDesc<PhysicsSendMethod> 004aa150 ("ErrorComputation" 0, "RoundRobin" 1) and
//              EnumDesc<PhysicsReceiveMethod> 004aa2c0 ("Direct" 0, "Interpolation" 1).
//   accessors  the PropDescriptor GetSetImpl RTTI (00823f10) types the getter `PhysicsSendMethod () const` and the
//              setter `void (const PhysicsSendMethod&)`; setters 004aad70 / 004aada0, getters ICF-shared
//              (00445220 / 006a6ee0).
#include "v8datamodel/GlobalSettings.h"

struct NativeServicesLayout;

namespace RBX
{
	extern const char sNetworkSettings[];

	class NetworkSettings : public GlobalSettingsItem<NetworkSettings, sNetworkSettings>
	{
		friend struct ::NativeServicesLayout; // tests/NativeServicesLayout.cpp offset asserts

	public:
		enum PhysicsSendMethod
		{
			ErrorComputation,
			RoundRobin
		};

		enum PhysicsReceiveMethod
		{
			Direct,
			Interpolation
		};

	public:
		bool printPhysicsErrors;                   // +0x130
		bool printInstances;                       // +0x131
		bool printProperties;                      // +0x132
		bool printPacketBuffer;                    // +0x133
		PhysicsSendMethod physicsSendMethod;       // +0x134
		PhysicsReceiveMethod physicsReceiveMethod; // +0x138
		int physicsReplicationUpdateRate;          // +0x13c
		bool test1;                                // +0x140
		bool test2;                                // +0x141
		bool test3;                                // +0x142
		bool test4;                                // +0x143
		int physicsMtuAdjust;                      // +0x144
		int replicationMtuAdjust;                  // +0x148
		int maxSendBuffer;                         // +0x14c
		float sendRate;                            // +0x150
		int maxSendBPS;                            // +0x154
		int minExtraPing;                          // +0x158
		int extraPingVariance;                     // +0x15c

	public:
		NetworkSettings();                         // 004aabc0

		PhysicsSendMethod getPhysicsSendMethod() const          // ICF-shared 00445220
		{
			return physicsSendMethod;
		}
		void setPhysicsSendMethod(const PhysicsSendMethod& value); // 004aad70

		PhysicsReceiveMethod getPhysicsReceiveMethod() const    // ICF-shared 006a6ee0
		{
			return physicsReceiveMethod;
		}
		void setPhysicsReceiveMethod(const PhysicsReceiveMethod& value); // 004aada0
	};
}

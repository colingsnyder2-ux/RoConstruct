// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::Replicator constructor 004b9bd0 and destructor 004b96b0 (inactive). Declarations and member
// layout in native-headers/Network/Replicator2008.h. Constructor statement order after the server-verified mined analog
// src/2008-06/004b9bd0.cpp. Destructor after the server-verified mined analog src/2008-06/004b96b0.cpp:
// the only user statement is peer->DetachPlugin(this) (RakPeerInterface slot 59, +0xec, PluginInterface subobject
// +0x2b74) behind a NULL test; the members are then destroyed in reverse declaration order (+0x2d48 .. +0x2b80).
#include "Network/Replicator2008.h"
#include "Network/ReplicatorMarker.h"
#include "util/Profiling.h"
#include "RakPeerInterface.h"
#include "Network/NetworkSettings.h"
#include "Network/PhysicsSenders2008.h"
#include <G3D/System.h>
#include "reflection/signal.h"

namespace RBX
{
	namespace Network
	{
		// Dynamic initializer 007f2170 (registry placeholder func_007f2170; atexit 007fc320): SignalDesc<Replicator,
		// void(std::string, bool)> constructor 004b3e00 (vtable 00824c98, RTTI .?AV?$SignalDesc@VReplicator@...) on
		// 009717d0 with "Disconnection" 008256a8, "peer" 00823258, "lostConnection" 008256b8 (donor Replicator.h
		// event_Disconnection). INFERRED: file-local here because Network/Replicator2008.h (not this lease) does not
		// declare the static member; the descriptor object and its constructor are the same.
		static Reflection::SignalDesc<Replicator, void(std::string, bool)> event_Disconnection("Disconnection", "peer", "lostConnection");

		// 004b9bd0 (ret 0xc): DescribedNonCreatable 004b9ad0, PluginInterface 0049ed30, G3D::System::time 00508410,
		// DescriptorDictionary constructors 004b1570 / 004b1620, CodeProfiler(const char*) 005c43a0 ("Replication" ..
		// "Write"), CountProfiler(const char*) 005c43d0 ("Bits Received" .. "Split Messages Sent"), NetworkSettings
		// physicsSendMethod (+0x134: PhysicsSender 004ccb10 / RoundRobinPhysicsSender 004c99c0) and physicsReceiveMethod
		// (+0x138: inline DirectPhysicsReceiver / InterpolatingPhysicsReceiver 004b5e80), AttachPlugin (slot 58, +0xe8),
		// SystemAddress::ToString 004a98b0 on the argument, Instance::setName 0055af90, profiler parents (+0xc040).
		Replicator::Replicator(SystemAddress remotePlayerId, RakPeerInterface* peer)
			: lastSendTime(G3D::System::time()),
			  players(NULL),
			  sendPhysicsEnabled(false),
			  deserializeProperty(NULL),
			  removingInstance(NULL),
			  profileReplication(new Profiling::CodeProfiler("Replication")),
			  profileDataListening(new Profiling::CodeProfiler("Data Listening")),
			  profileDataIn(new Profiling::CodeProfiler("Data In")),
			  profileDataOut(new Profiling::CodeProfiler("Data Out")),
			  profilePhysicsIn(new Profiling::CodeProfiler("Physics In")),
			  profilePhysicsOut(new Profiling::CodeProfiler("Physics Out")),
			  profileStep(new Profiling::CodeProfiler("Step")),
			  profileWrite(new Profiling::CodeProfiler("Write")),
			  profileBitsReceived(new Profiling::CountProfiler("Bits Received")),
			  profileBitsSent(new Profiling::CountProfiler("Bits Sent")),
			  profileUnsplitMessagesSent(new Profiling::CountProfiler("Unsplit Messages Sent")),
			  profileSplitMessagesSent(new Profiling::CountProfiler("Split Messages Sent")),
			  receivedGlobals(false),
			  disconnected(false),
			  peer(peer),
			  remotePlayerId(remotePlayerId),
			  counter0(0),
			  lastReceivedName(NULL)
		{
			switch (NetworkSettings::singleton().physicsSendMethod)
			{
			case NetworkSettings::ErrorComputation:
				physicsSender.reset(new PhysicsSender(this));
				break;
			case NetworkSettings::RoundRobin:
				physicsSender.reset(new RoundRobinPhysicsSender(this));
				break;
			}

			switch (NetworkSettings::singleton().physicsReceiveMethod)
			{
			case NetworkSettings::Direct:
				physicsReceiver.reset(new DirectPhysicsReceiver(this));
				break;
			case NetworkSettings::Interpolation:
				physicsReceiver.reset(new InterpolatingPhysicsReceiver(this));
				break;
			}

			if (peer)
				peer->AttachPlugin(this);

			Instance::setName(remotePlayerId.ToString(true));

			profileDataListening->parent = profileReplication.get();
			profileDataIn->parent = profileReplication.get();
			profileDataOut->parent = profileReplication.get();
			profilePhysicsIn->parent = profileReplication.get();
			profilePhysicsOut->parent = profileReplication.get();
			profileStep->parent = profilePhysicsOut.get();
			profileWrite->parent = profilePhysicsOut.get();
		}

		// 004b96b0
		Replicator::~Replicator()
		{
			if (peer)
				peer->DetachPlugin(this);
		}
	}
}

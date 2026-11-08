#pragma once
// 2008-06 native RBX::Network::Peer (inactive). Shape after the donor tools/rbxgs Client/Network/Replicator.h (class
// Peer); every base, field and virtual below is read from the 2008-06 binary:
//   RTTI       vtable 00824944 .?AVPeer@Network@RBX@@ (21 bases) -> Described<Peer, sPeer, Instance> (name mangled
//              $1?sPeer@23@3QBDB, a const char array in .rdata at 008244d8 holding "NetworkPeer": classDescriptor
//              0049ea10), PluginInterface (mdisp 0x130, vtable 00824898) and Listener<RunService, Heartbeat>
//              (mdisp 0x134, vtable 0082488c). Not creatable: no FactoryProduct base.
//   size       0x144: Client (0x150) and Server (0x184) place their first own member / empty Service at 0x144+.
//   fields     constructor 004b4640 / destructor 004ac830:
//              +0x138 scoped_ptr<PacketLogger> logger (constructor stores 0; destructor deletes through slot 0),
//              +0x13c scoped_ptr<Profiling::CodeProfiler> profilePacketsThread (new(0xc048), CodeProfiler(const
//              char*) 005c43a0 with "Packets Thread" 00824cdc; CodeProfiler vtable 00838c5c),
//              +0x140 scoped_ptr<RakPeer> rakPeer (reset(new(0x910) ProfiledRakPeer(profiler)): RakPeer() 004c18d0,
//              profiler at +0x908, ProfiledRakPeer vtable 008245cc), then rakPeer->AttachPlugin(this) (slot 58,
//              +0xe8, PluginInterface subobject +0x130). The destructor calls rakPeer->DetachPlugin(this) (slot 59,
//              +0xec), deletes the three members in reverse order, then ~PluginInterface 0049ed40 and ~Instance 0055a540.
//   vtable     slot 2 askAddChild 0049ee20 (dynamic_cast<const Replicator*>: declared only, needs a native 2008
//              Replicator), slot 12 onServiceProvider 004b5700 (declared only); PluginInterface slots keep the RakNet
//              defaults (OnReceive 0049ed50); Listener slot 0 onEvent 004add50 (declared only). Deleting destructor
//              004ad7a0 (free: Creatable<Instance> operator delete), adjustor thunks 004ac940..004ac9d0.
// RakNet first: RakPeer.h pulls winsock2 before the windows.h that Instance.h reaches (as ProfiledRakPeer.cpp).
#include "ProfiledRakPeer.h"
#include "PluginInterface.h"
#include "PacketLogger.h"
#include "v8tree/Instance.h"
#include "util/RunStateOwner.h"
#include <boost/scoped_ptr.hpp>

class RakPeerInterface;

struct NativeNetworkClientServer2008Layout;

namespace RBX
{
	namespace Network
	{
		class Replicator;

		extern const char sPeer[];

		class Peer : public Reflection::Described<Peer, sPeer, Instance>,
					 public PluginInterface,
					 public Listener<RunService, Heartbeat>
		{
			friend struct ::NativeNetworkClientServer2008Layout; // NetworkClientServer2008Layout.cpp offset asserts

		private:
			boost::scoped_ptr<PacketLogger> logger;                                 // +0x138
			boost::scoped_ptr<Profiling::CodeProfiler> profilePacketsThread;        // +0x13c

		protected:
			boost::scoped_ptr<RakPeer> rakPeer;                                     // +0x140

		protected:
			Peer();                                                                 // 004b4640
			virtual ~Peer();                                                        // 004ac830 (deleting 004ad7a0)
			virtual bool askAddChild(const Instance* instance) const;               // 0049ee20
			virtual void onEvent(const RunService* source, Heartbeat event);       // 004add50
			virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider); // 004b5700
		};
	}
}

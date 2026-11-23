// =============================================================================
// PhysicsReplication.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/network/include/network/PhysicsReplication.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <boost/noncopyable.hpp>
#include <G3D/System.h>
#include <G3D/Vector3.h>
#include "v8world/MechanismTracker.h" // RBX::MechanismTracker (2008 shape; was the global v8world/Mechanism.h stub)

struct NativeNetworkPhysicsLayout;

namespace RakNet
{
	class BitStream;
}

namespace RBX
{
	class Assembly;
	class SimJob;

	namespace Network
	{
		class Replicator;

		class __declspec(novtable) IPhysicsSender : boost::noncopyable
		{
		public:
			virtual ~IPhysicsSender() {}
			virtual void step() = 0;                                              // slot 1
			virtual int sendPackets(int maxPackets) = 0;                          // slot 2
			static void readPosition(RakNet::BitStream& bitStream, G3D::Vector3& position);
			static void writePosition(RakNet::BitStream& bitStream, const G3D::Vector3& position, bool fullPrecision);
		};

		class __declspec(novtable) IPhysicsReceiver : boost::noncopyable
		{
		public:
			virtual ~IPhysicsReceiver() {}
			virtual void step(unsigned int time) = 0;                             // slot 1
			virtual void receivePacket(RakNet::BitStream& bitStream, unsigned int timeStamp) = 0; // slot 2
		};

		class DirectPhysicsReceiver : public IPhysicsReceiver
		{
			friend struct ::NativeNetworkPhysicsLayout; // tests/NativeNetworkPhysicsLayout.cpp offset asserts
		private:
			Replicator* replicator;                                               // +0x4

		public:
			DirectPhysicsReceiver(Replicator* replicator)                         // inlined in Replicator 004ba117
				: replicator(replicator)
			{
			}
			/*override*/ virtual void step(unsigned int time);                    // 0070bdf0 (empty)
			/*override*/ virtual void receivePacket(RakNet::BitStream& bitStream, unsigned int timeStamp); // 004c83b0
		};

		class RoundRobinPhysicsSender : public IPhysicsSender
		{
			friend struct ::NativeNetworkPhysicsLayout; // tests/NativeNetworkPhysicsLayout.cpp offset asserts
		public:
			class JobSender;
		private:
			// Assembly +0x24 root clump / Clump +0x1c root primitive, then PartInstance 00599f80). INFERRED name after
			void sendPhysicsData(RakNet::BitStream& bitStream, const Assembly* assembly);
			SimJob* findTargetPlayerCharacterMechanism();
		private:
			Replicator* replicator;                                               // +0x4
			MechanismTracker tracker;                                             // +0x8
			G3D::RealTime lastSendTime;                                           // +0x10

		public:
			RoundRobinPhysicsSender(Replicator* replicator);                      // 004c99c0
			/*override*/ virtual void step();                                     // 0047d410 (empty)
			/*override*/ virtual int sendPackets(int maxPackets);                 // 004cd420
		};
	}
}

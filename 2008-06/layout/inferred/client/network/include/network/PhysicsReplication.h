#pragma once
#include <boost/noncopyable.hpp>
#include <G3D/System.h>
#include "v8world/Mechanism.h"

struct NativeNetworkPhysicsLayout;

namespace RakNet
{
	class BitStream;
}

namespace RBX
{
	namespace Network
	{
		class Replicator;

		class __declspec(novtable) IPhysicsSender : boost::noncopyable
		{
		public:
			virtual ~IPhysicsSender() {}
			virtual void step() = 0;                                              // slot 1
			virtual int sendPackets(int maxPackets) = 0;                          // slot 2
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

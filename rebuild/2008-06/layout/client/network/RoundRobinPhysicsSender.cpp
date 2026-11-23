// =============================================================================
// RoundRobinPhysicsSender.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/network/RoundRobinPhysicsSender.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#define NATIVE_REPLICATOR_NO_STATS_ITEM // Network/Replicator2008.h: v8datamodel/Workspace.h brings its own Stats::Item
#include "Network/PhysicsReplication.h"
#include "Network/Replicator2008.h"
#include "Network/NetworkSettings.h"
#include "v8world/SimJob2008.h"
#include "v8world/SimJobStage2008.h" // SimJobStage::reportMechanisms 004cbad0 (sendPackets)
#include "v8world/World2008.h"       // World::getSimJobStage 005e93b0
#include "v8datamodel/Workspace.h"   // Workspace::getWorld (+0x2e4)
#include "AppUnit49C_2008/Streaming2008.h"
#include "BitStream.h"
#include <RakPeerInterface.h>
#include <GetTime.h>

namespace RBX
{
	namespace Network
	{
		RoundRobinPhysicsSender::RoundRobinPhysicsSender(Replicator* replicator)
			: replicator(replicator)
			, lastSendTime(G3D::System::time())
		{
		}

		void IPhysicsSender::writePosition(RakNet::BitStream& bitStream, const G3D::Vector3& position, bool fullPrecision)
		{
			// The target's compares are the negated `>` / `<` forms (fcom; test ah,5; jnp / test ah,0x41; je).
			if (!fullPrecision
				&& !(position.x > 1024.0f) && !(position.x < -1024.0f)
				&& !(position.y > 512.0f) && !(position.y < -512.0f)
				&& !(position.z > 1024.0f) && !(position.z < -1024.0f))
			{
				bitStream << true;
				unsigned short x = (unsigned short)((position.x - -1024.0f) * 16.0f);
				unsigned short y = (unsigned short)((position.y - -512.0f) * 16.0f);
				unsigned short z = (unsigned short)((position.z - -1024.0f) * 16.0f);
				if (x >= 0x8000)
					x = 0xffff;
				if (y >= 0x4000)
					y = 0xffff;
				if (z >= 0x8000)
					z = 0xffff;
				bitStream.WriteBits((const unsigned char*)&x, 15);
				bitStream.WriteBits((const unsigned char*)&y, 14);
				bitStream.WriteBits((const unsigned char*)&z, 15);
			}
			else
			{
				bitStream << false;
				bitStream.WriteVector(position.x, position.y, position.z);
			}
		}

		void RoundRobinPhysicsSender::step()
		{
		}

		class RoundRobinPhysicsSender::JobSender
		{
		private:
			const Assembly* firstA;                                               // +0x0   INFERRED: donor member; zeroed, never read here
			const SimJob* firstM;                                                 // +0x4   INFERRED: donor member; zeroed, never read here
			RoundRobinPhysicsSender& sender;                                      // +0x8
			RakPeerInterface* peer;                                               // +0xc
			bool hasOpenPacket;                                                   // +0x10
			int maxStreamSize;                                                    // +0x14  (report: `cmp eax, [esi+0x14]; setl`)
			RakNet::BitStream bitStream;                                          // +0x18  (BitStream(int) 004a50c0)
			PacketPriority packetPriority;                                        // +0x12c (MEDIUM_PRIORITY)
		public:
			int packetCount;                                                      // +0x130

		private:
			void closePacket();                                                   // 004c9a10
		public:
			JobSender(RoundRobinPhysicsSender& sender, RakPeerInterface* peer);   // 004cbd40
			~JobSender();                                                         // 004c9a70
			bool report(SimJob* job);                                             // 004cac30
		};

		RoundRobinPhysicsSender::JobSender::JobSender(RoundRobinPhysicsSender& sender, RakPeerInterface* peer)
			: firstA(NULL)
			, firstM(NULL)
			, sender(sender)
			, peer(peer)
			, hasOpenPacket(false)
			, maxStreamSize(peer->GetMTUSize(sender.replicator->remotePlayerId) + NetworkSettings::singleton().physicsMtuAdjust)
			, bitStream(maxStreamSize)
			, packetPriority(MEDIUM_PRIORITY)
			, packetCount(0)
		{
		}

		RoundRobinPhysicsSender::JobSender::~JobSender()
		{
			if (hasOpenPacket)
				closePacket();
		}

		void RoundRobinPhysicsSender::JobSender::closePacket()
		{
			if (bitStream.GetNumberOfBytesUsed() > 0)
			{
				sender.replicator->serializeId(bitStream, NULL);
				peer->Send(&bitStream, packetPriority, RELIABLE_SEQUENCED, 0, sender.replicator->remotePlayerId, false);
			}
			hasOpenPacket = false;
		}

		bool RoundRobinPhysicsSender::JobSender::report(SimJob* job)
		{
			if (!hasOpenPacket)
			{
				bitStream.Reset();
				bitStream << (unsigned char)24;
				bitStream << (int)RakNet::GetTime();
				bitStream << (unsigned char)80;
				++packetCount;
				hasOpenPacket = true;
			}
			sender.sendPhysicsData(bitStream, job->getAssemblyConst());
			return bitStream.GetNumberOfBytesUsed() < maxStreamSize;
		}

		int RoundRobinPhysicsSender::sendPackets(int maxPackets)
		{
			JobSender jobSender(*this, replicator->peer);
			if (Workspace* workspace = ServiceProvider::find<Workspace>(replicator))
			{
				SimJobStage& stage = workspace->getWorld()->getSimJobStage();
				SimJob* characterJob = findTargetPlayerCharacterMechanism();
				if (characterJob)
				{
					G3D::RealTime now = G3D::System::time();
					if (now > lastSendTime + 0.1f) // 00826938 holds (double)0.1f
					{
						jobSender.report(characterJob);
						lastSendTime = now;
					}
					else
					{
						characterJob = NULL;
					}
				}
				stage.reportMechanisms(jobSender, tracker, characterJob);
			}
			return jobSender.packetCount;
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

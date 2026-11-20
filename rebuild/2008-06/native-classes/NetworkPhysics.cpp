// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network physics sender/receiver classes (inactive); evidence in
// native-headers/Network/PhysicsReplication.h. Verified by tests/record_native_network_physics.py.
// Rows compiled here: RoundRobinPhysicsSender constructor 004c99c0, its scalar deleting destructor 004ca010, the
// empty step() 0047d410 (identical-code folded), the out-of-line inline ~MechanismTracker 004c99b0;
// DirectPhysicsReceiver scalar deleting destructor 004ab5b0 and the empty step(unsigned) 0070bdf0 (both folded);
// IPhysicsSender::writePosition 004ca7b0 (with its BitStream::WriteVector<float> instance 004ca210).
// RoundRobinPhysicsSender::JobSender (batch 28): constructor 004cbd40, destructor 004c9a70, closePacket 004c9a10 and
// report 004cac30 (body byte-identical; the registry size 129 B also covers the separate 17-byte function 004caca0).
// sendPackets 004cd420 (shape below) and receivePacket 004c83b0 are declared only (open).
#include "Network/PhysicsReplication.h"
#include "Network/Replicator2008.h"
#include "Network/NetworkSettings.h"
#include "v8world/SimJob2008.h"
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

		// 004ca7b0 (identity: cdecl (BitStream&, const Vector3&, bool), the mirror of IPhysicsSender::readPosition
		// 004ca5c0: a flag bit via operator<<(bool) 004a5b10, then either three WriteBits 004a5600 of 15/14/15 bits
		// (x and z in [-1024 00826744, 1024 00826750], y in [-512 00826748, 512 00826754], scaled by 16 00826918 to
		// unsigned short) or BitStream::WriteVector<float> 004ca210 when out of range or fullPrecision). /fp:fast: the
		// target loads the float constants as dword (the default model widens them to qword).
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

		// The sendPackets 004cd420 packet writer (sub esp 0x13c: the writer is 0x134 bytes at esp+8 after a double).
		// Layout from the constructor 004cbd40 (stores in declaration order) and the bodies below. The donor
		// Replicator::JobSender has the same members (firstA, firstM, owner, peer, hasOpenPacket, bitStream,
		// packetPriority, sentPacket); in 2008 the owner is the RoundRobinPhysicsSender, the stream is sized by the
		// MTU (+0x14) and +0x130 counts the opened packets (sendPackets returns it).
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

		// 004cbd40 (thiscall, ret 8): GetMTUSize (slot 0xb0) of the replicator's remote address plus
		// NetworkSettings PhysicsMtuAdjust (+0x144, singleton 0049e890) sizes the stream.
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

		// 004c9a70
		RoundRobinPhysicsSender::JobSender::~JobSender()
		{
			if (hasOpenPacket)
				closePacket();
		}

		// 004c9a10: terminates the packet with a NULL id (serializeId 004a8ae0) and sends it RELIABLE_SEQUENCED (4)
		// at the writer's priority (Send slot 0x34).
		void RoundRobinPhysicsSender::JobSender::closePacket()
		{
			if (bitStream.GetNumberOfBytesUsed() > 0)
			{
				sender.replicator->serializeId(bitStream, NULL);
				peer->Send(&bitStream, packetPriority, RELIABLE_SEQUENCED, 0, sender.replicator->remotePlayerId, false);
			}
			hasOpenPacket = false;
		}

		// 004cac30 (thiscall, ret 4): opens a packet when none is open (Reset 004a51c0, ID_TIMESTAMP 0x18,
		// RakNet::GetTime 004c9910, packet id 0x50), writes the job's assembly (SimJob slot 1) through
		// sendPhysicsData 004caaf0 and reports whether the stream still fits.
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

		// 004cd420 sendPackets: PENDING (not compiled). Shape (donor Replicator::sendPhysicsPacket):
		//   JobSender jobSender(*this, replicator->peer);
		//   if (Workspace* workspace = ServiceProvider::find<Workspace>(replicator))        // 00491e50
		//   {
		//       SimJobStage& stage = workspace->getWorld()->getSimJobStage();             // [+0x2e4], 005e93b0
		//       SimJob* job = <character job> (004ca040: findTargetPlayer slot 17 -> character +0x170 ->
		//                     getPrimaryPart -> Mechanism::getMechanismFromPrimitive 005e50c0 of its Primitive +0x228);
		//       if (job) { RealTime t = System::getLocalTime(); if (t > lastSendTime + 0.1f /*00826938*/)
		//                  { jobSender.report(job); lastSendTime = t; } else job = NULL; }
		//       stage.<reportJobs>(jobSender, tracker, job);                               // 004cbad0 (ret 0xc)
		//   }
		//   return jobSender.packetCount;
		// Blockers: 004cbad0 is a SimJobStage member template (thiscall on the stage; walks simJobs +0x10 with
		// getNextSimJob 004cb480 and MechanismTracker::tracking 005e50e0 / setSimJob 005e5350, calling report 004cac30
		// per job except `job`) that v8world/SimJobStage2008.h does not declare; 004ca040 needs
		// Mechanism::getMechanismFromPrimitive, which v8world/SimJob2008.h's 2008 RBX::Mechanism does not declare.

		void DirectPhysicsReceiver::step(unsigned int)
		{
		}

		// DirectPhysicsReceiver's constructor is inline (the Replicator constructor 004ba117 expands it). The
		// Replicator is not recovered natively, so this non-original helper expands the same `new` to make this unit
		// emit the DirectPhysicsReceiver vtable and scalar deleting destructor: a codegen analog, not the original unit.
		IPhysicsReceiver* nativeNetworkPhysicsNewDirectReceiver(Replicator* replicator)
		{
			return new DirectPhysicsReceiver(replicator);
		}
	}
}

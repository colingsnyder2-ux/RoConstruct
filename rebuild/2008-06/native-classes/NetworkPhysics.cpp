// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network physics sender/receiver classes (inactive); evidence in
// native-headers/Network/PhysicsReplication.h. Verified by tests/record_native_network_physics.py.
// Rows compiled here: RoundRobinPhysicsSender constructor 004c99c0, its scalar deleting destructor 004ca010, the
// empty step() 0047d410 (identical-code folded), the out-of-line inline ~MechanismTracker 004c99b0;
// DirectPhysicsReceiver scalar deleting destructor 004ab5b0 and the empty step(unsigned) 0070bdf0 (both folded);
// IPhysicsSender::writePosition 004ca7b0 (with its BitStream::WriteVector<float> instance 004ca210).
// sendPackets 004cd420 and receivePacket 004c83b0 are declared only (open).
#include "Network/PhysicsReplication.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "BitStream.h"

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

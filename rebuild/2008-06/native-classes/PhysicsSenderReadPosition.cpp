// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native IPhysicsSender::readPosition 004ca5c0 (declared in Network/PhysicsReplication.h; no other unit
// defines it) and the RakNet BitStream::ReadVector<float> instance 004ca0f0 it calls. Flags copied from
// NetworkPhysics.cpp, which holds the writer twin IPhysicsSender::writePosition 004ca7b0 / WriteVector<float> 004ca210.
// This file is its own unit only because NetworkPhysics.cpp is not owned by this batch (MotorDefaultCtor.cpp pattern).
#include <stdexcept>
#include <string>
#include "Network/PhysicsReplication.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "BitStream.h"

namespace RBX
{
	namespace Network
	{
		// 004ca5c0 (cdecl; callers InterpolatingPhysicsReceiver::PartItem::receive 004c8150 and
		// DirectPhysicsReceiver::receivePacket). Mirror of writePosition: a flag bit (operator>>(bool) 004a5b30), then
		// either three ReadBits 004a5210 of 15/14/15 bits (x and z offset by 1024 00826750, y by 512 00826754, scaled
		// by 1/16 00826884) or BitStream::ReadVector<float> 004ca0f0. Each failed read throws std::runtime_error with
		// the strings 008268e8 / 008268b8 / 00826888 / 00826850 (runtime_error(const string&) 00409d50, throw info
		// 008d1bc8).
		void IPhysicsSender::readPosition(RakNet::BitStream& bitStream, G3D::Vector3& position)
		{
			bool compressed;
			bitStream >> compressed;
			if (compressed)
			{
				unsigned short x;
				unsigned short y;
				unsigned short z = 0;
				if (!bitStream.ReadBits((unsigned char*)&x, 15))
					throw std::runtime_error("IPhysicsSender::readPosition failed reading x");
				if (!bitStream.ReadBits((unsigned char*)&y, 14))
					throw std::runtime_error("IPhysicsSender::readPosition failed reading y");
				if (!bitStream.ReadBits((unsigned char*)&z, 15))
					throw std::runtime_error("IPhysicsSender::readPosition failed reading z");
				position.x = x / 16.0f - 1024.0f;
				position.y = y / 16.0f - 512.0f;
				position.z = z / 16.0f - 1024.0f;
			}
			else
			{
				if (!bitStream.ReadVector(position.x, position.y, position.z))
					throw std::runtime_error("IPhysicsSender::readPosition failed reading vector");
			}
		}
	}
}

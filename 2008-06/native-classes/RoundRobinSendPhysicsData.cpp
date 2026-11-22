// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::RoundRobinPhysicsSender::sendPhysicsData 004caaf0 (inactive), declared in
// Network/PhysicsReplication.h. The body belongs to the RoundRobinPhysicsSender unit (NetworkPhysics.cpp); it has its
// own file because it needs the native Clump / Joint headers (NATIVE_CLUMP_DECL, part-embedded native-body Primitive),
// so NetworkPhysics.cpp's flags and includes stay unchanged. Flags follow the sender units (/fp:fast).
//
// BLOCKED (guard below): (1) core v8tree/Instance.h does not declare Instance::isAncestorOf 004c9c50
// (?isAncestorOf@Instance@RBX@@QBE_NPBV12@@Z, registry; thiscall, ret 4); (2) Network/Replicator2008.h (not this
// lease) keeps findTargetPlayer (slot 17, `call [edx+0x44]`) protected and has no `friend class
// RoundRobinPhysicsSender;` (PhysicsSender / InterpolatingPhysicsReceiver already have that friendship).
// Measured once (b37 nw01) with scratch copies of both headers carrying those two lines: 312 B, IDENTICAL to the target
// with relocations masked. The registry row is still the placeholder func_004caaf0 (no candidate name).
#ifdef ROUNDROBIN_SENDER_HEADERS_DECLARE_ISANCESTOROF
#define NATIVE_PRIMITIVE_NATIVE_BODY
#define NATIVE_CLUMP_DECL
#define NATIVE_REPLICATOR_NO_STATS_ITEM
#include "Network/PhysicsReplication.h"
#include "Network/Replicator2008.h"
#include "Network/Player.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "v8world/AssemblyLayout.h"
#include "v8world/Joints2008.h"
#include "util/Quaternion.h"
#include "util/Math.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include <BitStream.h>

namespace RBX
{
	namespace Network
	{
		// 004caaf0 (registry placeholder func_004caaf0; thiscall, ret 8; INFERRED name after the donor
		// Replicator::sendPhysicsData(BitStream&, const Assembly&)). Evidence: NULL assembly returns; root clump
		// (+0x24) -> root primitive (+0x1c) -> PartInstance::fromPrimitive 00599f80; isSerializePending 004aeac0 and
		// trySerializeId 004a8cc0 on the replicator (+0x4); getCoordinateFrame 00598cb0; findTargetPlayer slot 17,
		// its character (+0x170) and isAncestorOf 004c9c50 select full precision for writePosition 004ca7b0;
		// Quaternion(const Matrix3&) 005dd570, normalize 004c9d40, WriteNormQuat 004a5dd0 (w, x, y, z); numMotors
		// 005e62d0, operator<<(uchar) 004a6350, per motor Assembly::getMotor 005e6400 -> currentAngle +0x8c (0 when
		// NULL) -> Math::rotationToByte 005ded60.
		void RoundRobinPhysicsSender::sendPhysicsData(RakNet::BitStream& bitStream, const Assembly* assembly)
		{
			if (!assembly)
				return;

			PartInstance* part = PartInstance::fromPrimitive(assembly->getRootClump()->getRootPrimitive());
			if (!part || replicator->isSerializePending(part))
				return;

			if (!replicator->trySerializeId(bitStream, part))
				return;

			const G3D::CoordinateFrame& cf = part->getCoordinateFrame();

			Player* player = replicator->findTargetPlayer();
			IPhysicsSender::writePosition(bitStream, cf.translation,
				player && player->getCharacter() && player->getCharacter()->isAncestorOf(part));

			Quaternion q(cf.rotation);
			q.normalize();
			bitStream.WriteNormQuat(q.w, q.x, q.y, q.z);

			Assembly* a = const_cast<Assembly*>(assembly);
			int motors = a->numMotors();
			bitStream << (unsigned char)motors;
			for (int i = 0; i < motors; i++)
			{
				float angle = 0.0f;
				if (MotorJoint* motor = a->getMotor(i))
					angle = motor->getCurrentAngle();
				unsigned char value = Math::rotationToByte(angle);
				bitStream << value;
			}
		}
	}
}
#endif

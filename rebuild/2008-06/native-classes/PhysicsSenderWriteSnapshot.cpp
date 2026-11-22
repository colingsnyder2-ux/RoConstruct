// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::PhysicsSender::writePhysicsSnapshot (inactive), declared (INFERRED name) in
// Network/PhysicsSenders2008.h. The body belongs to the PhysicsSender unit (NetworkPhysicsSenders2008.cpp); like
// RoundRobinSendPhysicsData.cpp it has its own file because it needs the native PartInstance / Assembly / Joint
// headers (part-embedded Primitive), so the sender unit's flags and includes stay unchanged.
#define NATIVE_PRIMITIVE_NATIVE_BODY
#define NATIVE_CLUMP_DECL
#define NATIVE_REPLICATOR_NO_STATS_ITEM
#include "Network/PhysicsSenders2008.h"
#include "Network/Replicator2008.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/AssemblyLayout.h"
#include "v8world/Joints2008.h"
#include "util/Quaternion.h"
#include "util/Math.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include <BitStream.h>
#include <boost/bind.hpp>
#include <algorithm>
#include <set>

namespace RBX
{
	namespace Network
	{
		// 004ca980 (registry placeholder func_004ca980; thiscall, ret 8; INFERRED name in PhysicsSenders2008.h). Evidence:
		// item.part (+0) -> isSerializePending 004aeac0 and trySerializeId 004a8cc0 on replicator (+0x3c), both returning
		// false; getCoordinateFrame 00598cb0; writePosition 004ca7b0 with full precision when 20.0f (008222f0) > item.error
		// (+0x48); Quaternion(const Matrix3&) 005dd570, inline normalization, WriteNormQuat 004a5dd0 (w, x, y, z); the
		// part's Primitive (+0x228) getAssembly 005e7570, numMotors 005e62d0 (0 without an assembly), operator<<(uchar)
		// 004a6350, per motor getMotor 005e6400 -> currentAngle +0x8c (0.0f when NULL) -> Math::rotationToByte 005ded60.
		// NEAR MISS (batch 42): 352 of 362 bytes, identical through the inline normalization's sum; the remaining
		// difference is the x87 scheduling of the four products (target `fld st(0); fmulp st(3)` ... `fst`) and the
		// branch offsets after it. Rejected: a file-local inline helper (not inlined), `q *= inverse`, `(float)sqrt`.
		bool PhysicsSender::writePhysicsSnapshot(RakNet::BitStream& bitStream, const PartItem& item)
		{
			PartInstance* part = item.part.get();
			if (replicator->isSerializePending(part))
				return false;

			if (!replicator->trySerializeId(bitStream, part))
				return false;

			const G3D::CoordinateFrame& cf = part->getCoordinateFrame();
			IPhysicsSender::writePosition(bitStream, cf.translation, item.error < 20.0f);

			// INFERRED: the target expands the normalization inline (fsqrt, fld1/fdivrp, products stored back into q),
			// while core util/Quaternion.h declares Quaternion::normalize out of line (copies 004c9d40 /
			// AppUnit5DC_2008Quaternion.cpp); a file-local inline helper was not inlined by /Ob2 (measured).
			Quaternion q(cf.rotation);
			float inverse = 1.0f / (float)sqrt(q.z * q.z + q.y * q.y + q.x * q.x + q.w * q.w);
			q.x *= inverse;
			q.y *= inverse;
			q.z *= inverse;
			q.w *= inverse;
			bitStream.WriteNormQuat(q.w, q.x, q.y, q.z);

			Assembly* assembly = part->getPrimitive()->getAssembly();
			int motors = assembly ? assembly->numMotors() : 0;
			bitStream << (unsigned char)motors;
			for (int i = 0; i < motors; i++)
			{
				float angle = 0.0f;
				if (MotorJoint* motor = assembly->getMotor(i))
					angle = motor->getCurrentAngle();
				unsigned char value = Math::rotationToByte(angle);
				bitStream << value;
			}
			return true;
		}
	}
}

// 004cc720 (registry placeholder func_004cc720; cdecl, hidden functor return): std::for_each over the PhysicsService
// parts set (std::set<PartInstance*> +0x138, head +0x150; const_iterator::_Inc 005e9340) that PhysicsSender::step
// 004cd920 runs with boost::bind(&PhysicsSender::addPhysicsInstance 004cd170, this, boost::bind(&shared_from<
// PartInstance> 00618a40, _1)): the 0x18-byte functor built at 004cd9f4..004cda12 (pmf 004cd170 + adjustment 0, this,
// 00618a40), its call operator 004cbb60 (inner bind 004cb3c0, mf1 call 00587420). step itself is not recovered, so the
// algorithm is instantiated explicitly here.
namespace
{
	typedef boost::_bi::bind_t<boost::shared_ptr<RBX::PartInstance>, boost::shared_ptr<RBX::PartInstance> (*)(RBX::PartInstance*),
		boost::_bi::list1<boost::arg<1> > > SenderSharedFromPart;
	typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, RBX::Network::PhysicsSender, boost::shared_ptr<RBX::Instance> >,
		boost::_bi::list2<boost::_bi::value<RBX::Network::PhysicsSender*>, SenderSharedFromPart> > SenderAddPart;
}
template SenderAddPart std::for_each(std::set<RBX::PartInstance*>::iterator, std::set<RBX::PartInstance*>::iterator, SenderAddPart);

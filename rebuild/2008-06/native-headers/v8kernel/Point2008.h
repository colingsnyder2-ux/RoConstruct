#pragma once
// >>> native-status (generated) -- do not edit >>>
// Point2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 217c158e | roc native-status --write
// 2008-06 native RBX::Point on the 2008 Body of native-headers/v8kernel/Body2008.h (inactive). Declared under a
// non-colliding name: the donor v8kernel/Point.h includes the donor v8kernel/Body.h (root +0x4, pv +0x88 there), and is
// reached through native-headers/v8kernel/Connector2008.h and leaves2008/Point2008.h; a unit must not include both
// this header and the donor v8kernel/Point.h (or anything that reaches it).
// Every field, slot and size is read from the 2008-06 binary (the same layout as the donor declaration):
//   RTTI     vtable 0084b24c .?AVPoint@RBX@@ -> KernelIndex at +0x4 (non-polymorphic base after the vptr); one slot,
//            the scalar deleting destructor 0064dc50.
//   ctor     0064dc00 Point(Body*) (`ret 4`): kernelIndex +0x4 = -1, numOwners +0x8 = 1, body +0xc (argument, or
//            Body::getWorldBody() 00614bb0 when NULL), localPos +0x10, worldPos +0x1c, force +0x28 zeroed; size 0x34
//            (counted by leaves2008-working.json against the donor header, not rebuilt here).
//   step     0064dc90: worldPos = body pv.position (+0x94, read directly: no Body::updatePV call) * localPos, then
//            force = Vector3::zero().
//   forceToBody 0064dc70: body->root (+0x10)->simBody (+0x2c)->accumulateForce(force, worldPos) (00612fb0).
//   setWorldPos 0064dd40: worldPos = argument; localPos = body->getCoordinateFrame() (updatePV 00599360, pv +0x94 /
//            translation +0xb8) .pointToObjectSpace(worldPos).
// The connector bodies read worldPos +0x1c (PointToPointBreakConnector::computeForce 006065d0, NormalBreakConnector::
// computeForce 00606670) and accumulate into force +0x28.
#include <G3D/Vector3.h>
#include "v8kernel/KernelIndex.h"
#include "v8kernel/Body2008.h"

struct NativeBodyPrimitive2008Layout;

namespace RBX
{
	class Point : public KernelIndex
	{
		friend struct ::NativeBodyPrimitive2008Layout;

	public:
		int numOwners;                                    // +0x8

	protected:
		Body* body;                                       // +0xc
		G3D::Vector3 localPos;                            // +0x10
		G3D::Vector3 worldPos;                            // +0x1c
		G3D::Vector3 force;                               // +0x28

	public:
		Point(Body* _body);                               // 0064dc00
		virtual ~Point()                                  // slot 0 (??_G 0064dc50)
		{
		}

		void step();                                      // 0064dc90
		void forceToBody();                               // 0064dc70
		void setWorldPos(const G3D::Vector3& _worldPos);  // 0064dd40
		void accumulateForce(const G3D::Vector3& _force)
		{
			force += _force;
		}
		Body* getBody()
		{
			return body;
		}
		const G3D::Vector3& getWorldPos()
		{
			return worldPos;
		}
	};
}

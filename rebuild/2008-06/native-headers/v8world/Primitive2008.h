#pragma once
// 2008-06 native RBX::Primitive (inactive), declared only by the members whose evidence is a call: no field, base or
// virtual is declared, so this class must not be used for new, sizeof, member access or a vtable. Declared under a
// non-colliding name: the original path v8world/Primitive.h is reached by every unit that includes PartInstance.h /
// World.h, and a unit must not include both this header and the donor v8world/Primitive.h.
// Layout evidence gathered for a later complete declaration (not declared here; see the body-primitive2008 receipt):
//   size 0xfc (Part unit, part-lifetime receipt), vtable 0083f83c stored at +0x0 by Primitive() 005e8770; Guid at +0x8
//   (Guid() 005a8300); geometry +0x9c (= newGeometry 005e7d80), body +0xa0 (= new Body, 0xdc), friction +0xb0 = 0,
//   elasticity +0xb4 (constant 0082f840), jointK ComputeProp +0xe8..+0xf8 (+0xe8 = 00976384, a function-local static
//   initialized under guard 00976390; byte +0xf0 = 1; +0xf4 = this; member pointer computeJointK 005e7580 at +0xf8);
//   the fields +0x4..+0x98 and +0xa4..+0xe4 are written by the constructor but not yet assigned to declarations.
#include "util/Extents.h"

namespace RBX
{
	class Primitive
	{
	public:
		static void onNewTouch(Primitive* p0, Primitive* p1);   // 005e7530 (Contact::step 00606c6f)
		const Extents& getFastFuzzyExtents() const;            // 005e7a50 (00606ce6 / 00606cee)
	};
}

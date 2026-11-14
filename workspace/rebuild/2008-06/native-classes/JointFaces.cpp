// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "v8world/Joint.h"
#include "util/Face.h"
#include "util/Math.h"

namespace RBX
{
	class Primitive
	{
	public:
		__declspec(noinline) const G3D::CoordinateFrame& getCoordinateFrame() const;
		Face getFaceInWorld(NormalId objectFace);
	};

	IJointOwner* Joint::getJointOwner() const
	{
		return jointOwner;
	}

	bool Joint::canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1, float angleMax, float planarMax)
	{
		if (!Math::fuzzyAxisAligned(p0->getCoordinateFrame().rotation, p1->getCoordinateFrame().rotation, angleMax))
			return false;

		Face f0 = p0->getFaceInWorld(nId0);
		Face f1 = p1->getFaceInWorld(nId1);
		if (!Face::hasOverlap(f0, f1, 0.35f))
			return false;

		if (!Face::overlapWithinPlanes(f0, f1, planarMax))
			return false;

		return true;
	}
}

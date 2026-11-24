// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: header choice follows the 2008 sibling (Humanoid2008.h, sizeof 0x22c); targetPoint at +0x1dc.
// INFERRED: PartInstance lives in v8datamodel (v8tree/PartInstance.h does not exist).
// INFERRED: Humanoid2008.h does not declare propTargetPoint; the code pushes the static descriptor at 0x97a4b0.
// PropertyDescriptor is abstract, so declare the object as raw storage and cast to a reference.
#include "humanoid/Humanoid2008.h"
#include "v8datamodel/PartInstance.h"
#include <algorithm>
#include <cmath>

extern "C" char g_0097a4b0[];

namespace RBX
{
	// INFERRED: local stand-in for Math::taxiCabMagnitude (|x|+|y|+|z|), matches the fabs/faddp sequence.
	static inline float taxiCab(const G3D::Vector3& v)
	{
		return fabsf(v.x) + fabsf(v.y) + fabsf(v.z);
	}

	void Humanoid::setTargetPoint(const G3D::Vector3& value)
	{
		float tolerance = 1.0f;
		if (getTorso())
		{
			float torsoToTarget = taxiCab(getTorso()->getCoordinateFrame().translation - value);
			tolerance = std::max(2.0f, torsoToTarget) * 0.01f;
		}

		if (taxiCab(value - targetPoint) > tolerance)
		{
			targetPoint = value;
			raisePropertyChanged(*reinterpret_cast<const Reflection::PropertyDescriptor*>(g_0097a4b0));
		}
	}
}

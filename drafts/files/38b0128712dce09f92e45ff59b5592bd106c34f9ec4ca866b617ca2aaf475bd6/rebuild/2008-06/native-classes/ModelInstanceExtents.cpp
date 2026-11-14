// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// Inactive native 2008-06 recovery: RBX::ModelInstance flag height and front/top orientation (v8datamodel/ModelInstance.cpp
// range 00583520..00583c88). Flags copied from AppUnit57C_2008ModelInstance.cpp (same unit, /fp:fast for x87 order).
// The header-inline ModelInstance bodies (setModelInPrimary 005834c0, getExtentsWorld 00584a50, getExtentsLocal 00584aa0,
// getPrimaryPart/getPrimaryPartConst via 00584b10 and its vtordisp thunks 00584b20 / 005907e0 / 005a2c60) are already
// defined in native-headers/v8datamodel/ModelInstance.h and are not duplicated here.
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	// 00583520: 6.0f at 00826e74; both Extents come from vtable slot 0x54 (getExtentsWorld), high.y at +0x10.
	float ModelInstance::computeFlagHeight() const
	{
		float answer = 6.0f;

		if (primaryPart)
		{
			float primaryPartY = primaryPart->getExtentsWorld().max().y;
			answer = (getExtentsWorld().max().y - primaryPartY) + 6.0f;
		}

		return answer;
	}

	// 00583ba0: CoordinateFrame() 004782d0, lookAt 00518e20, PartInstance::getCoordinateFrame 00598cb0,
	// Matrix3::transpose 00513510 / operator* 00513350 / operator= 00513220, Vector3::zero static 0096f044;
	// the ComputeProp dirty bytes +0x240 / +0x270 / +0x20c are dirtyAll inlined (its body is in the same original unit;
	// it is out of line in AppUnit57C_2008ModelInstance.cpp, so this split unit spells the three setDirty calls).
	void ModelInstance::setFrontAndTop(const G3D::Vector3& lookVector)
	{
		if (primaryPart)
		{
			G3D::CoordinateFrame lookFrame;
			lookFrame.lookAt(lookVector);
			modelInPrimary = G3D::CoordinateFrame(primaryPart->getCoordinateFrame().rotation.transpose() * lookFrame.rotation, G3D::Vector3::zero());
			LocalGridExtents.setDirty();
			WorldGridExtents.setDirty();
			FlagHeight.setDirty();
		}
	}
}

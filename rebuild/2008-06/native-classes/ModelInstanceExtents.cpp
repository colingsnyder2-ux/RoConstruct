// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
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

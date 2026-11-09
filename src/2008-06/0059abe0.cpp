// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_81bc87fb53fa5f20.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/PartInstance.h"
#include "v8world/Primitive.h"
#include "AppDraw/HitTest.h"
namespace RBX {
bool PartInstance::hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint)
	{
		const G3D::CoordinateFrame& cframe = reinterpret_cast<const Primitive*>(reinterpret_cast<const char*>(this) + 0x228)->getCoordinateFrame();
		G3D::Ray rayInPartCoords = cframe.toObjectSpace(worldRay);
		G3D::Vector3 hitPointInPartCoords;

		if (HitTest::hitTest(getPart(), rayInPartCoords, hitPointInPartCoords, 1.0f))
		{
			const G3D::CoordinateFrame& cframe = reinterpret_cast<const Primitive*>(reinterpret_cast<const char*>(this) + 0x228)->getCoordinateFrame(); // roblox be like: lets do it again why not
			worldHitPoint = cframe.pointToWorldSpace(hitPointInPartCoords);
			return true;
		}
		else
		{
			return false;
		}
	}

	
}

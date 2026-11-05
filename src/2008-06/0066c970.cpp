// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_unit_4bcacccd78e95d4b.cpp

// Candidate translation unit (score above; library headers required).
#define private public
#define protected public
#undef _RELEASEASSERT
#include "tool/RunDragger.h"
#include "tool/Dragger.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Filters.h"
#include "v8datamodel/Surfaces.h"
#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/Workspace.h"
#include "v8world/Primitive.h"
#include "v8world/Contact.h"
#include "v8world/ContactManager.h"

namespace RBX
{
	// 2008-06 layout from the target: Primitive::geometry at +0x9c.
	struct Primitive2008View
	{
		char prefix[0x9c];
		Geometry* geometry;
		Extents getExtentsLocal() const
		{
			G3D::Vector3 hVec = geometry->getGridSize() * 0.5f;
			return Extents(-hVec, hVec);
		}
	};

	RunDragger::SnapInfo RunDragger::createSnapSurface(Primitive* snap, G3D::Array<NormalId>* ignore)
	{
		RBXASSERT(snap);

		SnapInfo answer;
		answer.snap = snap;

		Extents snapExtents = ((Primitive2008View*)snap)->getExtentsLocal();
		const G3D::CoordinateFrame& cframe = snap->getCoordinateFrame();
		G3D::Ray rayInSnap = cframe.toObjectSpace(mouseRay);

		float bestDistance = 0.0f;
		bool found = false;

		for (int i = 0; i < 6; i++)
		{
			NormalId id = (NormalId)i;

			if (!ignore || ignore->find(id) == ignore->end())
			{
				G3D::Plane plane = snapExtents.getPlane(id);
				if (plane.halfSpaceContainsFinite(rayInSnap.origin))
				{
					G3D::Vector3 hitInSnap;
					if (Math::intersectRayPlane(rayInSnap, plane, hitInSnap))
					{
						G3D::Vector3 hitWorld = cframe.pointToWorldSpace(hitInSnap);
						float distance = (mouseRay.origin - hitWorld).magnitude();
						if (distance > bestDistance)
						{
							bestDistance = distance;
							answer.surface = id;
							found = true;
							answer.hitWorld = hitWorld;
						}
					}
				}
			}
		}
		
		return found ? answer : SnapInfo();
	}
}


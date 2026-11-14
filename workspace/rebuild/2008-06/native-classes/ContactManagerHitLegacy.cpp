// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/engine-world
#include "v8world/ContactManager.h"

namespace RBX
{
	Primitive* ContactManager::getHitLegacy(const G3D::Ray& originDirection, const Primitive* ignorePrim, const HitTestFilter* filter,
		G3D::Vector3& hitPointWorld, float& distanceToHit, const float& maxSearchDepth) const
	{
		G3D::Ray searchRay = G3D::Ray::fromOriginAndDirection(originDirection.origin, originDirection.direction * maxSearchDepth);

		G3D::Array<const Primitive*> ignore;
		if (ignorePrim)
			ignore.append(ignorePrim);

		Primitive* hit = getHit(searchRay, &ignore, filter, hitPointWorld);
		distanceToHit = hit ? (hitPointWorld - searchRay.origin).length() : 0.0f;
		return hit;
	}
}

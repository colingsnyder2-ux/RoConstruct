// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/engine-world
// ContactManager::getHitLegacy, 2008-06 ContactManager unit (0060cae0..0060dd5f). The body scales the ray direction by
// maxSearchDepth (G3D::Ray::fromOriginAndDirection 00518830), wraps the single ignore primitive in a local
// G3D::Array (append 005ccf20), calls getHit(Ray, Array*, ...) 0060d6e0 with the default ContactManager::ignoreBool
// (0097beb8) and returns the distance from the scaled ray origin to the hit point (0 when nothing was hit).
#include "v8world/ContactManager.h"

namespace RBX
{
	// 0060da00
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

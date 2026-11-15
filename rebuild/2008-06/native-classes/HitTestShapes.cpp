// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
#include "AppDraw/HitTest.h"
#include "G3D/CollisionDetection.h"
#include "G3D/AABox.h"
#include "G3D/Capsule.h"
#include "G3D/Sphere.h"

namespace RBX
{
	bool HitTest::hitTestBox(const Part& part, G3D::Ray& rayInPartCoords, G3D::Vector3& hitPointInPartCoords, float gridToReal)
	{
		G3D::Vector3 halfRealSize = part.gridSize * gridToReal * 0.5;
		return G3D::CollisionDetection::collisionLocationForMovingPointFixedAABox(
			rayInPartCoords.origin, rayInPartCoords.direction,
			G3D::AABox(-halfRealSize, halfRealSize), hitPointInPartCoords);
	}

	bool HitTest::hitTestBall(const Part& part, G3D::Ray& rayInPartCoords, G3D::Vector3& hitPointInPartCoords, float gridToReal)
	{
		float radius = part.gridSize.x * gridToReal * 0.5;
		return G3D::CollisionDetection::collisionTimeForMovingPointFixedSphere(
			rayInPartCoords.origin, rayInPartCoords.direction,
			G3D::Sphere(G3D::Vector3::ZERO3, radius), hitPointInPartCoords) != G3D::inf();
	}

	bool HitTest::hitTestCylinder(const Part& part, G3D::Ray& rayInPartCoords, G3D::Vector3& hitPointInPartCoords, float gridToReal)
	{
		float radius = part.gridSize.z * gridToReal * 0.5;
		G3D::Vector3 p0(part.gridSize.x * gridToReal * 0.5, 0, 0);
		return G3D::CollisionDetection::collisionTimeForMovingPointFixedCapsule(
			rayInPartCoords.origin, rayInPartCoords.direction,
			G3D::Capsule(G3D::Vector3::ZERO3, p0, radius), hitPointInPartCoords) != G3D::inf();
	}
}

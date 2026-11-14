// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 AppDraw/HitTest.cpp shape tests (inactive): HitTest::hitTestBall 00677190, hitTestCylinder 00677260 and
// hitTestBox 00677300, declared by AppDraw/HitTest.h (Part::gridSize at +0x4). hitTest 00677380 dispatches to them
// (called by PartInstance 0059abe0). Callees: CollisionDetection::collisionTimeForMovingPointFixedSphere 007bb5a0,
// collisionTimeForMovingPointFixedCapsule 007bba50, collisionLocationForMovingPointFixedAABox 007bb770,
// Capsule::Capsule 00525fe0, Vector3::ZERO3 0097381c, G3D::inf() static 0096f018, 0.5f 00819bac.
#include "AppDraw/HitTest.h"
#include "G3D/CollisionDetection.h"
#include "G3D/AABox.h"
#include "G3D/Capsule.h"
#include "G3D/Sphere.h"

namespace RBX
{
	// 00677300
	bool HitTest::hitTestBox(const Part& part, G3D::Ray& rayInPartCoords, G3D::Vector3& hitPointInPartCoords, float gridToReal)
	{
		G3D::Vector3 halfRealSize = part.gridSize * gridToReal * 0.5;

		return G3D::CollisionDetection::collisionLocationForMovingPointFixedAABox(
			rayInPartCoords.origin,
			rayInPartCoords.direction,
			G3D::AABox(-halfRealSize, halfRealSize),
			hitPointInPartCoords
		);
	}

	// 00677190: Sphere (vtable 00827404) on the stack under an EH frame
	bool HitTest::hitTestBall(const Part& part, G3D::Ray& rayInPartCoords, G3D::Vector3& hitPointInPartCoords, float gridToReal)
	{
		float radius = part.gridSize.x * gridToReal * 0.5;

		return G3D::CollisionDetection::collisionTimeForMovingPointFixedSphere(
			rayInPartCoords.origin,
			rayInPartCoords.direction,
			G3D::Sphere(G3D::Vector3::ZERO3, radius),
			hitPointInPartCoords
		) != G3D::inf();
	}

	// 00677260
	bool HitTest::hitTestCylinder(const Part& part, G3D::Ray& rayInPartCoords, G3D::Vector3& hitPointInPartCoords, float gridToReal)
	{
		float radius = part.gridSize.z * gridToReal * 0.5;

		G3D::Vector3 p0(part.gridSize.x * gridToReal * 0.5, 0, 0);

		return G3D::CollisionDetection::collisionTimeForMovingPointFixedCapsule(
			rayInPartCoords.origin,
			rayInPartCoords.direction,
			G3D::Capsule(G3D::Vector3::ZERO3, p0, radius),
			hitPointInPartCoords
		) != G3D::inf();
	}
}

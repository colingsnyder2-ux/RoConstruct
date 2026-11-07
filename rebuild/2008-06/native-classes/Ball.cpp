// 2008-06 native RBX::Ball (inactive); evidence in native-headers/v8world/Ball2008.h.
// Verified by tests/record_native_world_shapes.py. Unit 00649130..006492bc (getMomentSolid, getGridVolume,
// onSetSize, hitTest).
// >>> native-status (generated) -- do not edit >>>
// Ball | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src bfdf6b9e | roc native-status --write
#include "v8world/Ball2008.h"
#include "util/Math.h"
#include <G3D/Sphere.h>
#include <G3D/CollisionDetection.h>

namespace RBX
{
	// 00649130: the diagonal is written x, y, z from one product; Math::fromDiagonal 005ddbd0.
	G3D::Matrix3 Ball::getMomentSolid(float mass) const
	{
		G3D::Vector3 diagonal;
		diagonal.z = diagonal.y = diagonal.x = realRadius * realRadius * mass * 0.4f;
		return Math::fromDiagonal(diagonal);
	}

	// 00649170: radius = gridSize.x * 0.5f; radius^3 times 4/3 pi (one folded constant).
	float Ball::getGridVolume() const
	{
		float radius = gridSize.x * 0.5f;
		return radius * radius * radius * ((4.0f / 3.0f) * Math::pi());
	}

	// 00649190
	void Ball::onSetSize()
	{
		realRadius = gridSize.x * 0.5f;
	}

	// 006491a0
	bool Ball::hitTest(const G3D::Ray& rayInMe, G3D::Vector3& localHitPoint, bool& inside)
	{
		float distanceSquared = rayInMe.origin.squaredMagnitude();
		inside = distanceSquared <= realRadius * realRadius;

		G3D::Sphere sphere(G3D::Vector3::zero(), realRadius);
		return G3D::CollisionDetection::collisionTimeForMovingPointFixedSphere(
			rayInMe.origin,
			rayInMe.direction,
			sphere,
			localHitPoint) != G3D::inf();
	}
}

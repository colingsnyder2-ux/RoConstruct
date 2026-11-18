#include "v8world/Ball2008.h"
#include "util/Math.h"
#include <G3D/Sphere.h>
#include <G3D/CollisionDetection.h>

namespace RBX
{
	G3D::Matrix3 Ball::getMoment(float mass) const
	{
		return getMomentSolid(mass);
	}

	G3D::Matrix3 Ball::getMomentSolid(float mass) const
	{
		G3D::Vector3 diagonal;
		diagonal.z = diagonal.y = diagonal.x = realRadius * realRadius * mass * 0.4f;
		return Math::fromDiagonal(diagonal);
	}

	float Ball::getGridVolume() const
	{
		float radius = gridSize.x * 0.5f;
		return radius * radius * radius * ((4.0f / 3.0f) * Math::pi());
	}

	void Ball::onSetSize()
	{
		realRadius = gridSize.x * 0.5f;
	}

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

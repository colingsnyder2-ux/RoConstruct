#include "v8kernel/Body2008.h"
#include "v8kernel/Constants.h"
#include "util/Units.h"

namespace RBX
{
	static inline G3D::Vector3 reciprocal(const G3D::Vector3& v)
	{
		return G3D::Vector3(1.0f / v.x, 1.0f / v.y, 1.0f / v.z);
	}

	SimBody::SimBody(Body* _body)
		: body(_body),
		  dt(0.0f),
		  dirty(true),
		  constantForceY(0.0f),
		  force(G3D::Vector3::zero()),
		  torque(G3D::Vector3::zero()),
		  impulse(G3D::Vector3::zero()),
		  rotImpulse(G3D::Vector3::zero())
	{
	}

	void SimBody::update()
	{
		{
			const G3D::Vector3 cofmOffset = body->getCofmOffset();
			pv = body->getPV().pvAtLocalOffset(cofmOffset);
		}
		qOrientation = Quaternion(pv.position.rotation);
		qOrientation *= 1.0f / qOrientation.magnitude();
		angMomentum = pv.velocity.rotational * body->getBranchIWorld();
		massRecip = 1.0f / body->getBranchMass();
		momentRecip = reciprocal(Math::toDiagonal(body->getBranchIBody()));
		constantForceY = body->getBranchMass() * Units::kmsAccelerationToRbx(Constants::getKmsGravity()).y;
		dirty = false;
	}

	PV SimBody::getOwnerPV()
	{
		G3D::Vector3 cofmOffset = body->getCofmOffset();
		return pv.pvAtLocalOffset(G3D::Vector3(-cofmOffset.x, -cofmOffset.y, -cofmOffset.z));
	}

	void SimBody::accumulateForce(const G3D::Vector3& _force, const G3D::Vector3& worldPos)
	{
		updateIfDirty();
		force += _force;
		torque += (worldPos - pv.position.translation).cross(_force);
	}

	void SimBody::accumulateImpulse(const G3D::Vector3& _impulse, const G3D::Vector3& worldPos)
	{
		updateIfDirty();
		impulse += _impulse;
		rotImpulse += (worldPos - pv.position.translation).cross(_impulse);
	}
}

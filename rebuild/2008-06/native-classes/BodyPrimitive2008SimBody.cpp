// 2008-06 native RBX::SimBody rows (inactive) against native-headers/v8kernel/Body2008.h (the 0xb4 SimBody):
// SimBody(Body*) 00658ae0, getOwnerPV 00658ca0 (SimBody unit 00658a30..0065925e) and accumulateForce 00612fb0 (its
// out-of-line copy precedes the GeoPair unit 00613060). Verified by tests/record_native_body_primitive2008.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// BodyPrimitive2008SimBody | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src ae4f411d | roc native-status --write
#include "v8kernel/Body2008.h"
#include "v8kernel/Constants.h"
#include "util/Units.h"

namespace RBX
{
	static inline G3D::Vector3 reciprocal(const G3D::Vector3& v)
	{
		return G3D::Vector3(1.0f / v.x, 1.0f / v.y, 1.0f / v.z);
	}

	// 00658ae0: dt +0x4 = 0, dirty +0x8, PV() +0xc, Quaternion() +0x54 = (0, 0, 0, 1), angMomentum / momentRecip zeroed by
	// Vector3(), constantForceY +0x80 = 0, then the four accumulators from the Vector3::zero() static (0096f044).
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

	// 00658d20
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

	// 00658ca0
	PV SimBody::getOwnerPV()
	{
		G3D::Vector3 cofmOffset = body->getCofmOffset();
		return pv.pvAtLocalOffset(G3D::Vector3(-cofmOffset.x, -cofmOffset.y, -cofmOffset.z));
	}

	// 00612fb0
	void SimBody::accumulateForce(const G3D::Vector3& _force, const G3D::Vector3& worldPos)
	{
		updateIfDirty();
		force += _force;
		torque += (worldPos - pv.position.translation).cross(_force);
	}
}

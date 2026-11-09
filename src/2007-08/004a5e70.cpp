// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8kernel/SimBody.cpp

// Candidate translation unit (score above; library headers required).
#include "v8kernel/SimBody.h"

#include "decomp.h"
#include "util/Math.h"
#include "util/Units.h"
#include "v8kernel/Body.h"
#include "v8kernel/Cofm.h"
#include "v8kernel/Constants.h"

#include <cstddef>

namespace RBX {

// FUNCTION: WEBSERVICE 0x10120e00
inline void mulMatrixMatrixTranspose(const Matrix3& _mat0, const Matrix3& _mat1, Matrix3& _answer)
{
	const Matrix3& mat0 = _mat0;
	const Matrix3& mat1 = _mat1;
	Matrix3& answer = _answer;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			answer[i][j] = mat0[i][0] * mat1[j][0] + mat0[i][1] * mat1[j][1] + mat0[i][2] * mat1[j][2];
		}
	}
}

// FUNCTION: WEBSERVICE 0x10120e80
inline Vector3 computeRotVel(const Matrix3& rot, const Vector3& momentRecip, const Vector3& angMomentum)
{
	Matrix3 iWorldInv;
	Matrix3 temp;

	temp[0][0] = rot[0][0] * momentRecip.x;
	temp[0][1] = rot[0][1] * momentRecip.y;
	temp[0][2] = rot[0][2] * momentRecip.z;
	temp[1][0] = rot[1][0] * momentRecip.x;
	temp[1][1] = rot[1][1] * momentRecip.y;
	temp[1][2] = rot[1][2] * momentRecip.z;
	temp[2][0] = rot[2][0] * momentRecip.x;
	temp[2][1] = rot[2][1] * momentRecip.y;
	temp[2][2] = rot[2][2] * momentRecip.z;

	mulMatrixMatrixTranspose(temp, rot, iWorldInv);

	Vector3 rotVel;

	for (int r = 0; r < 3; ++r) {
		float sum = iWorldInv[r][0] * angMomentum[0] + iWorldInv[r][1] * angMomentum[1];

		rotVel[r] = sum + iWorldInv[r][2] * angMomentum[2];
	}

	return rotVel;
}

// FUNCTION: WEBSERVICE 0x101210b0
SimBody::SimBody(Body* body)
	: body(body), dirty(true), qOrientation(0.0f, 0.0f, 0.0f, 1.0f), angMomentum(0.0f, 0.0f, 0.0f),
	  momentRecip(0.0f, 0.0f, 0.0f), constantForceY(0.0f), force(Vector3::zero()), torque(Vector3::zero())
{
}

// FUNCTION: WEBSERVICE 0x10121190
PV SimBody::getOwnerPV()
{
	Vector3 cofmInBody = body->getCofmOffset();

	return pv.pvAtLocalOffset(-cofmInBody);
}

// FUNCTION: WEBSERVICE 0x10121210
void SimBody::update()
{
	Vector3 cofmInBody = body->getCofmOffset();
	pv = body->getPV().pvAtLocalOffset(cofmInBody);

	qOrientation = Quaternion(pv.position.rotation);
	qOrientation.normalize();

	angMomentum = pv.velocity.rotational * body->getBranchIWorld();

	massRecip = 1.0f / body->getBranchMass();
	momentRecip = Vector3(1.0f, 1.0f, 1.0f) / Math::toDiagonal(body->getBranchIBody());
	constantForceY = body->getBranchMass() * Units::kmsAccelerationToRbx(Constants::getKmsGravity()).y;

	dirty = false;
}

// FUNCTION: WEBSERVICE 0x10121490
void SimBody::step(float dt)
{
	static Vector3 denormFix(1e-20f, 1e-20f, 1e-20f);

	updateIfDirty();

	angMomentum *= 0.9998f;
	angMomentum += torque * dt;

	pv.velocity.rotational = computeRotVel(pv.position.rotation, momentRecip, angMomentum) + denormFix;

	qOrientation += Quaternion(pv.velocity.rotational, 0.0f) * qOrientation * 0.5f * dt;
	qOrientation.normalize();
	qOrientation.toRotationMatrix(pv.position.rotation);

	pv.velocity.linear += force * massRecip * dt;
	pv.position.translation += pv.velocity.linear * dt;

	clearAccumulators();

	angMomentum += denormFix;
	pv.velocity.linear += denormFix;
}

// FUNCTION: WEBSERVICE 0x1015b610 FOLDED
SimBody::~SimBody()
{
}

} // namespace RBX

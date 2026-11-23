#include "v8kernel/Body2008.h"

namespace RBX
{
	void mulMatrixMatrixTranspose(const G3D::Matrix3& _mat0, const G3D::Matrix3& _mat1, G3D::Matrix3& _answer)
	{
		const float* matrix0 = &_mat0[0][0];
		const float* matrix1 = &_mat1[0][0];
		float* answer = &_answer[0][0];

		for (int iRow = 0; iRow < 3; iRow++)
		{
			for (int iCol = 0; iCol < 3; iCol++)
			{
				answer[iRow*3+iCol] =
					matrix0[iRow*3+0] * matrix1[iCol*3+0] +
					matrix0[iRow*3+1] * matrix1[iCol*3+1] +
					matrix0[iRow*3+2] * matrix1[iCol*3+2];
			}
		}
	}

	G3D::Vector3 computeRotVel(const G3D::Matrix3& rot, const G3D::Vector3& momentRecip, const G3D::Vector3& angMomentum)
	{
		G3D::Matrix3 temp;
		G3D::Matrix3 iWorldInv;
		const float* matrix = &rot[0][0];
		float* answer = &temp[0][0];
		answer[0] = matrix[0] * momentRecip.x;
		answer[1] = matrix[1] * momentRecip.y;
		answer[2] = matrix[2] * momentRecip.z;
		answer[3] = matrix[3] * momentRecip.x;
		answer[4] = matrix[4] * momentRecip.y;
		answer[5] = matrix[5] * momentRecip.z;
		answer[6] = matrix[6] * momentRecip.x;
		answer[7] = matrix[7] * momentRecip.y;
		answer[8] = matrix[8] * momentRecip.z;
		mulMatrixMatrixTranspose(temp, rot, iWorldInv);
		return iWorldInv * angMomentum;
	}

	void SimBody::step()
	{
		static G3D::Vector3 denormalSmall(1e-20f, 1e-20f, 1e-20f);
		updateIfDirty();
		angMomentum *= 0.9998f;
		angMomentum += torque * dt + rotImpulse;
		pv.velocity.rotational = computeRotVel(pv.position.rotation, momentRecip, angMomentum) + denormalSmall;
		Quaternion qDot(Quaternion(pv.velocity.rotational, 0.0f) * qOrientation * 0.5f);
		qOrientation += qDot * dt;
		qOrientation *= 1.0f / qOrientation.magnitude();
		qOrientation.toRotationMatrix(pv.position.rotation);
		pv.velocity.linear += (dt * force + impulse) * massRecip;
		pv.position.translation += pv.velocity.linear * dt;
		force = G3D::Vector3(0.0f, constantForceY, 0.0f);
		torque = G3D::Vector3(0.0f, 0.0f, 0.0f);
		impulse = G3D::Vector3(0.0f, 0.0f, 0.0f);
		rotImpulse = G3D::Vector3(0.0f, 0.0f, 0.0f);
		angMomentum += denormalSmall;
		pv.velocity.linear += denormalSmall;
	}
}

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

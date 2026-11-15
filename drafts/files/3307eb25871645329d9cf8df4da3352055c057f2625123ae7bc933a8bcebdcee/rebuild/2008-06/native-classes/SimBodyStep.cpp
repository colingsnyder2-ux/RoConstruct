// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// Inactive native 2008-06 recovery: RBX::SimBody::step 00658fb0 (?step@SimBody@RBX@@QAEXXZ) of v8kernel/SimBody.cpp
// (SimBody unit 00658a30..0065925e), against the 0xb4 SimBody of native-headers/v8kernel/Body2008.h (read-only).
// Flags: the sibling rows of native-classes/BodyPrimitive2008SimBody.cpp (/fp:fast).
// resetAccumulators 00613e80 is already defined inline in Body2008.h (out-of-line COMDAT), so it is not redefined here.
// Evidence read from 00658fb0:
//   - function-local static Vector3 at 0097d94c (guard bit 1 of 0097d958) initialized from 1e-20f (0084c224) in all
//     three components; added to the rotational velocity, to angMomentum and to the linear velocity.
//   - angMomentum (+0x64) *= 0.9998f (0084c220), then += torque * dt (+0x90, dt +0x4) + rotational impulse (+0xa8).
//   - computeRotVel 00658920 (?computeRotVel@RBX@@YA?AVVector3@G3D@@ABVMatrix3@3@ABV23@1@Z, cdecl, same unit, not
//     natively recovered yet) with pv.position.rotation +0xc, momentRecip +0x70, angMomentum.
//   - Quaternion(rotational, 0) * qOrientation (00658a30, folded with G3D::Quat::operator*) * 0.5f (00819bac) * dt
//     added into qOrientation +0x54, inline normalize, then Quaternion::toRotationMatrix 005dd6d0 into pv.rotation.
//   - pv.velocity.linear +0x3c += (force * dt + impulse) * massRecip (+0x84 / +0x9c / +0x7c);
//     translation +0x30 += linear * dt; the four accumulators reset without the dirty check.
// PARKED (pass 1: 685 B vs 687 B, first divergence insn 129 at 0065912c): only x87 operand order differs. The inline normalize
// emits `fld [y]; fmul st(1)` where the original has `fld st(0); fmul [y]`; the force * dt and linear * dt products
// start with `fld st(0); fmul [mem]` instead of `fld [mem]; fmul st(1)`; one `fst [+0x8c]` is scheduled before
// `pop edi`; and the last two denormal adds load the member first. Rejected: massRecip * (impulse + force * dt)
// (fixes the linear add, breaks the translation add), no /fp:fast (970 B, qword constants and spills), and
// qOrientation = qOrientation * (1 / magnitude) (702 B, different register allocation).
// Near-miss pass 2 (workflow 53, VS2008 RTM 21022): ADOPTED (dt * force + impulse) * massRecip through the G3D free
// operator*(float, const Vector3&) (Vector3.h, returns v * s): 687 B = target size; it fixes the linear add, the
// translation add and the `fst [+0x8c]` / `pop edi` schedule. Remaining (16 diff lines, still first divergence insn 129):
// normalize y `fld st(0); fmul [edi+4]`, force.x `fld [esi+0x84]; fmul st(1)`, and the angMomentum denormal y/z adds
// load the static first. The sibling update() 00658d20 normalize has a different mixed pattern (x and y `fld st(0);
// fmul [m]`), so the per-component order is register-stack scheduling, not per-component source order.
// Rejected in pass 2: VS2005 50727 (same source: new divergence at insn 5, guard test scheduled before push edi);
// flags /Ob1, no /Oy, /Ox, /Og /Oi /Ot /Oy /Ob2 (unchanged), /Oy- (682 B), /fp:precise (970 B); static const
// denormalSmall and a local Vector3& to the static (unchanged); dt * torque (685 B, new divergence insn 47);
// impulse + dt * force (unchanged); massRecip * (dt * force + impulse) (685 B); dt * pv.velocity.linear alone (685 B);
// explicit x *= invMagnitude per component (register swap ebx/edi from insn 18); 1 / sqrtf(dot) (684 B);
// qOrientation = qOrientation + qDot * dt (700 B).
#include "v8kernel/Body2008.h"

namespace RBX
{
	// 006588a0 (?mulMatrixMatrixTranspose@RBX@@YAXABVMatrix3@G3D@@0AAV23@@Z, cdecl; only caller computeRotVel 0065898a):
	// answer = mat0 * transpose(mat1), one row per loop pass (esi = 3) over flat float pointers.
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

	// 00658920 (?computeRotVel@RBX@@YA?AVVector3@G3D@@ABVMatrix3@3@ABV23@1@Z, cdecl; only caller step 00659062):
	// temp = rot scaled per column by momentRecip (nine inline products), iWorldInv = temp * transpose(rot) through
	// mulMatrixMatrixTranspose 006588a0, then the inline Matrix3 * Vector3.
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

	// 00658c50 (?pvAtLocalOffset@PV@RBX@@QBE?AV12@ABVVector3@G3D@@@Z): emitted inside the SimBody unit between
	// SimBody(Body*) 00658ae0 and getOwnerPV 00658ca0; Matrix3::identity 00513e20, Matrix3 copy 00513220, inline
	// translation copy, then pvAtLocalCoord 00658a00 (also in this unit). Its only callers are update 00658d0c and
	// getOwnerPV 00658d97. Defined here (not in BodyPrimitive2008SimBody.cpp) so it cannot be inlined into those callers.
	PV PV::pvAtLocalOffset(const G3D::Vector3& localOffset) const
	{
		G3D::CoordinateFrame cf(G3D::Matrix3::identity(), localOffset);
		return pvAtLocalCoord(cf);
	}

	// 00658fb0
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

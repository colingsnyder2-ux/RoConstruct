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
// PARKED (685 B vs 687 B, first divergence insn 129 at 0065912c): only x87 operand order differs. The inline normalize
// emits `fld [y]; fmul st(1)` where the original has `fld st(0); fmul [y]`; the force * dt and linear * dt products
// start with `fld st(0); fmul [mem]` instead of `fld [mem]; fmul st(1)`; one `fst [+0x8c]` is scheduled before
// `pop edi`; and the last two denormal adds load the member first. Rejected: massRecip * (impulse + force * dt)
// (fixes the linear add, breaks the translation add), no /fp:fast (970 B, qword constants and spills), and
// qOrientation = qOrientation * (1 / magnitude) (702 B, different register allocation).
#include "v8kernel/Body2008.h"

namespace RBX
{
	G3D::Vector3 computeRotVel(const G3D::Matrix3& rot, const G3D::Vector3& momentRecip, const G3D::Vector3& angMomentum);   // 00658920

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
		pv.velocity.linear += (force * dt + impulse) * massRecip;
		pv.position.translation += pv.velocity.linear * dt;
		force = G3D::Vector3(0.0f, constantForceY, 0.0f);
		torque = G3D::Vector3(0.0f, 0.0f, 0.0f);
		impulse = G3D::Vector3(0.0f, 0.0f, 0.0f);
		rotImpulse = G3D::Vector3(0.0f, 0.0f, 0.0f);
		angMomentum += denormalSmall;
		pv.velocity.linear += denormalSmall;
	}
}

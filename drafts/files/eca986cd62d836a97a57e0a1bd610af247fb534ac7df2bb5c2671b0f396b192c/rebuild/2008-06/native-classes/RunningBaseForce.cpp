// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// 2008-06 native RBX::HUMAN::RunningBase::onComputeForce 00666550 (inactive; vtable 0084cc38 slot 8), plus Freefall 006675d0 / Jumping 00667a40 onComputeForce (below). Not in any build list.
// Layout and the other RunningBase rows: native-headers/humanoid/HumanoidStates1.h, native-classes/HumanoidStates1.cpp.
//
// Evidence (2008-06 Roblox.exe, 00666550..00666975, `ret 4`):
//   Balancing::onComputeForce 0066e6a0 first; getHumanoid 00793d50 -> Humanoid::getTorsoBody 005d9160 / getRootBody
//   005d9180 (each returns early on NULL); Body::updatePV 00599360 then pv.velocity.rotational.y (+0xd4) of the root;
//   Humanoid walkRotationalVelocity +0x1b0 * 4.0f [00826e6c] + desiredYRotation +0xc4 + floorRotationalVelocity +0xb4;
//   Body::getBranchIBodyV3 0062e100 (twice), getBranchTorque 0062e2e0, gains 7500.0f [0084cc18] / 160000.0f [0084cc28],
//   G3D::clamp, Body::accumulateTorque 006060b0 with (0, t, 0).
//   Floor primitive 00643d30 (HumanoidState: floorPart +0x24 ? PartInstance +0x228 (embedded Primitive) : NULL);
//   branch masses inline (Cofm::getMass 0065ff10 or Body::mass +0x8c), smaller one kept (ties keep the root's);
//   desiredAltitude +0xc8 != 0: torso pv.translation.y (+0xbc), root pv.velocity.linear.y (+0xc8), 10000.0f [0082746c],
//   1250.0f [00847b94], getBranchForce 0062e2a0 .y / getBranchMass 00613f00, maxMoveForce 00666350 .y (HumanoidForceLimits.h),
//   accumulateForceAtBranchCofm 0062e140 on the root and SimBody::accumulateForce 00612fb0 (floor root +0x10 -> simBody
//   +0x2c) at floorTouchInWorld +0x2c with the negated force.
//   Move: desiredVelocity +0xb8 + floorVelocity +0xa8 (x / z only live), branch velocity root->root->simBody->pv.velocity
//   (+0x3c) or the function-local static Velocity::zero() 0097d568 (guard 0097d580, Velocity() 00614170), branch force /
//   branch mass (Vector3::operator/ 00518740), y gain only while desiredVelocity.y > 0, Vector3::clamp 004a6100 between
//   minMoveForce 006663a0 and maxMoveForce 00666350, times the mass; floor friction (Primitive +0xb0) < 0.3f [0082711c]
//   scales x / z by friction^2; accumulateForceAtBranchCofm 0062e140, then the negated force to the floor body.
//   The Body getters are called out of line here (COMDAT copies in the BodyMover range 0062e100..0062e2e0), as the
//   trial compile below also does.
//
// The batch-11 header proposals are landed (batch 12): Body2008.h has the inline branch members (getBranchIBodyV3,
// getBranchForce, getBranchTorque, getBranchVelocity, accumulateForceAtBranchCofm / SimBody::accumulateForceCofm),
// HumanoidState.h declares getFloorPrimitive 00643d30, Humanoid2008.h declares getTorsoBody / getRootBody, and this
// unit reaches Humanoid2008.h through NATIVE_HUMANOID_UNIT_CONNECTOR with the unit-local Connector below.
// PARKED near miss: 1066 bytes against 1061. Residual differences are x87 scheduling only: the negated floor force
// (0066679b..006667b6) is stored after the floor-body loads in the target, and the move block keeps desired x / z as
// separate spills and evaluates z after the y select. Rejected variant (batch 12): building desiredAccel with the
// three-argument Vector3 constructor (x, y-select, z) -> 1068 bytes, same divergences. All calls, constants and
// field offsets agree.
#include <G3D/Vector3.h>
#include <G3D/g3dmath.h>
#include <algorithm>
#include "util/Velocity.h"
#include "v8kernel/Body2008.h"
#include "v8world/Primitive2008.h"
#include "v8kernel/KernelIndex.h"
#include "humanoid/HumanoidStates1.h"
#include "humanoid/HumanoidStates2.h"

// Unit-local Connector, exactly as native-headers/v8kernel/Connector2008.h declares it (that header reaches the donor
// v8kernel/Body.h, which cannot share this unit with Body2008.h: C2011). Same pattern as BodyGyro.cpp; selected in
// Humanoid2008.h by NATIVE_HUMANOID_UNIT_CONNECTOR. No Connector or Humanoid vtable is emitted here.
namespace RBX
{
	class Body;

	class Connector : public KernelIndex
	{
	public:
		Connector() {}
		__declspec(noinline) int& getKernelIndex() { return kernelIndex; }
		virtual ~Connector() {}                                         // slot 0 (??_G 006062c0)
		virtual void computeForce(const float dt, bool throttling) = 0; // slot 1
		virtual bool canThrottle() const                                // slot 2 (00565950)
		{
			return true;
		}
		virtual bool getBroken()                                        // slot 3 (0060a2f0)
		{
			return false;
		}
		virtual Body* getBody(int i) = 0;                               // slot 4 (analog name)
		virtual float potentialEnergy()                                 // slot 5 (005e72c0)
		{
			return 0;
		}
	};
}

#define NATIVE_HUMANOID_UNIT_CONNECTOR
#include "humanoid/Humanoid2008.h"
#include "AppUnit664/HumanoidForceLimits.h"

namespace RBX {
namespace HUMAN {

// 00666550
void RunningBase::onComputeForce(float dt)
{
    Balancing::onComputeForce(dt);

    Body* torsoBody = getHumanoid()->getTorsoBody();
    if (!torsoBody)
        return;
    Body* rootBody = getHumanoid()->getRootBody();
    if (!rootBody)
        return;

    const Velocity& velocity = rootBody->getVelocity();
    float torqueY = (getHumanoid()->getWalkRotationalVelocity() * 4.0f + desiredYRotation + floorRotationalVelocity - velocity.rotational.y)
        * rootBody->getBranchIBodyV3().y * 7500.0f;
    torqueY -= rootBody->getBranchTorque().y;
    float maxTorqueY = rootBody->getBranchIBodyV3().y * 160000.0f;
    torqueY = G3D::clamp(torqueY, -maxTorqueY, maxTorqueY);
    rootBody->accumulateTorque(G3D::Vector3(0.0f, torqueY, 0.0f));

    Primitive* floorPrimitive = getFloorPrimitive();
    float mass;
    if (!floorPrimitive) {
        mass = rootBody->getBranchMass();
    } else {
        mass = std::min(rootBody->getBranchMass(), floorPrimitive->getBody()->getRoot()->getBranchMass());
        if (desiredAltitude != 0.0f) {
            float altitudeAccel = (desiredAltitude - torsoBody->getPos().y) * 10000.0f - rootBody->getVelocity().linear.y * 1250.0f;
            if (altitudeAccel > 0.0f) {
                float currentAccel = rootBody->getBranchForce().y / rootBody->getBranchMass();
                if (currentAccel < altitudeAccel) {
                    float upForce = std::min(altitudeAccel - currentAccel, maxMoveForce().y) * mass;
                    rootBody->accumulateForceAtBranchCofm(G3D::Vector3(0.0f, upForce, 0.0f));
                    floorPrimitive->getBody()->accumulateForce(G3D::Vector3(0.0f, -upForce, 0.0f), floorTouchInWorld);
                }
            }
        }
    }

    G3D::Vector3 targetVelocity = floorVelocity + desiredVelocity;
    const Velocity& branchVelocity = rootBody->getBranchVelocity();
    G3D::Vector3 currentAccel = rootBody->getBranchForce() / rootBody->getBranchMass();
    G3D::Vector3 desiredAccel = (targetVelocity - branchVelocity.linear) * 1250.0f;
    desiredAccel.y = desiredVelocity.y > 0.0f ? (desiredVelocity.y - branchVelocity.linear.y) * 1250.0f : currentAccel.y;
    G3D::Vector3 deltaAccel = desiredAccel - currentAccel;
    G3D::Vector3 clampedAccel = deltaAccel.clamp(minMoveForce(), maxMoveForce());
    G3D::Vector3 force = clampedAccel * mass;
    if (floorPrimitive) {
        float friction = floorPrimitive->getFriction();
        if (friction < 0.3f) {
            float scale = friction * friction;
            force.x *= scale;
            force.z *= scale;
        }
    }
    rootBody->accumulateForceAtBranchCofm(force);
    if (floorPrimitive)
        floorPrimitive->getBody()->accumulateForce(-force, floorTouchInWorld);
}

// Freefall::onComputeForce 006675d0 and Jumping::onComputeForce 00667a40 (drafts moved here from HumanoidStates2.cpp,
// whose constructors need the native PartInstance.h; that header reaches the donor v8kernel/Body.h, which cannot share
// a unit with Body2008.h). Freefall inlines the Body branch getters (moment copy 00513220 + Math::toDiagonal 005ddbb0,
// branch torque +0x90 / static zero 0096f044 under guard 0096f050, branch velocity +0x3c / static 0097d568, branch
// mass), and calls accumulateTorque 006060b0 and accumulateForceAtBranchCofm 0062e140 out of line.
// 00962aa8: writable .data float 120000.0f without a symbol; the yaw-torque limit gain.
// PARKED near miss (batch 13, 514 bytes = target size): the only differences are the stack frame (sub esp 0x60 against
// 0x54) and the second Math::toDiagonal result, which the target reads back from the shared stack temp ([esp + 0x24])
// while this compile reads [eax + 4]. Rejected variants: (1) both toDiagonal calls inline in the expressions -> 513 bytes,
// updatePV 00599360 is called before the first moment copy (target: moment first); (2) one named iBody local assigned
// twice -> worse (three-float copy of the second result). Next hypothesis (not tried, three-trial limit): the inline
// Body::getBranchIBodyV3() in both places (its out-of-line COMDAT 0062e100 is what RunningBase calls).
extern float freefallYawLimitGain;                       // 00962aa8 (analog name)

// 006675d0
void Freefall::onComputeForce(float dt)
{
    Balancing::onComputeForce(dt);
    Body* body = getHumanoid()->getRootBody();
    if (!body)
        return;
    G3D::Vector3 iBody = Math::toDiagonal(body->getBranchIBody());
    float torqueY = (desiredYRotationalVelocity - body->getVelocity().rotational.y) * iBody.y * 7500.0f;
    torqueY -= body->getBranchTorque().y;
    float maxTorqueY = Math::toDiagonal(body->getBranchIBody()).y * freefallYawLimitGain;
    body->accumulateTorque(G3D::Vector3(0.0f, G3D::clamp(torqueY, -maxTorqueY, maxTorqueY), 0.0f));
    G3D::Vector3 accel = (desiredVelocity - body->getBranchVelocity().linear) * 1250.0f;
    G3D::Vector3 clamped = accel.clamp(minMoveForce(), maxMoveForce());
    float mass = body->getBranchMass();
    body->accumulateForceAtBranchCofm(G3D::Vector3(clamped.x * mass, 0.0f, clamped.z * mass));
}

// 00667a40: Flying::onComputeForce 0070bdf0 called directly; flag11 (+0x11) set when there is no root body or the
// jump force (50.0f [0084ced4] - pv.velocity.linear.y +0xc8) * 5000.0f [0084ced0] is not positive. With a floor
// primitive (00643d30 called twice): floor root = primitive body +0xa0 -> root +0x10; std::min of the two branch masses
// (floor's evaluated first); the lift above getBranchForce 0062e2a0 .y goes to accumulateForceAtBranchCofm 0062e140 and
// the negated lift to the floor root (inline accumulateForce, SimBody::accumulateForce 00612fb0) at floorTouchInWorld.
// PARKED near miss (batch 13, 337 bytes = target size): one instruction is scheduled differently: the target loads the
// floor root's simBody (`mov ecx, [edx + 0x2c]`) before storing the (0, -delta, 0) temporary, this compile after it
// (the same x87/load scheduling residual as RunningBase above). Accepted steps: early returns setting flag11 (draft:
// nested ifs -> 343 bytes, `test ah, 5; jp` and the flag11 block moved to the end), and holding getBranchForce().y as a
// const float& (draft: Vector3 reference -> `fsub [ecx + 4]` without `add ecx, 4`).
void Jumping::onComputeForce(float dt)
{
    Flying::onComputeForce(dt);
    if (flag11)
        return;
    Body* body = getHumanoid()->getRootBody();
    if (!body) {
        flag11 = true;
        return;
    }
    float jumpForce = (50.0f - body->getVelocity().linear.y) * 5000.0f;
    if (jumpForce <= 0.0f) {
        flag11 = true;
        return;
    }
    if (getFloorPrimitive()) {
        Body* floorRoot = getFloorPrimitive()->getBody()->getRoot();
        float lift = std::min(body->getBranchMass(), floorRoot->getBranchMass()) * jumpForce;
        const float& currentY = body->getBranchForce().y;
        if (lift > currentY) {
            float delta = lift - currentY;
            body->accumulateForceAtBranchCofm(G3D::Vector3(0.0f, delta, 0.0f));
            floorRoot->accumulateForce(G3D::Vector3(0.0f, -delta, 0.0f), floorTouchInWorld);
        }
    }
}

}
}

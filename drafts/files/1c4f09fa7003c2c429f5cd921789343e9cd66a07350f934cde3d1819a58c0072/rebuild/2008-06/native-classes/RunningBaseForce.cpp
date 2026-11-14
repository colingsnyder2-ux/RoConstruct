// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// 2008-06 native RBX::HUMAN::RunningBase::onComputeForce 00666550 (inactive; vtable 0084cc38 slot 8). Not in any build list.
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

}
}

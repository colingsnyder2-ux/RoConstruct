// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /I/tmp/claude-0/-home-user/28a5ad2c-f9ca-5f88-a52d-b9a089ed390b/scratchpad/rbtrial
#include <G3D/Vector3.h>
#include <G3D/g3dmath.h>
#include <algorithm>
#include "Body2008x.h"
#include "v8world/Primitive2008.h"
#include "HumanoidStates1x.h"
#include "AppUnit664/HumanoidForceLimits.h"

namespace RBX {
class Humanoid {   // TRIAL stub: walkRotationalVelocity +0x1b0 (Humanoid2008.h)
public:
    char pad[0x1b0];
    float walkRotationalVelocity;
    float getWalkRotationalVelocity() const { return walkRotationalVelocity; }
    Body* getTorsoBody();   // 005d9160
    Body* getRootBody();    // 005d9180
};
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
    G3D::Vector3 force = deltaAccel.clamp(minMoveForce(), maxMoveForce()) * mass;
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

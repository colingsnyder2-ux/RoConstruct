// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Inactive native Freefall/Flying/Jumping/GettingUp methods (2008-06). Not in any build list.
// Bodies that read the stored humanoid call the out-of-line getter 00793d50 (HumanoidState::getHumanoid).
// >>> native-status (generated) -- do not edit >>>
// HumanoidStates2 | 2008-06 | draft (no current byte proof)
// 0/5 mapped addresses byte-exact | 5 unproved | no mapped strings | by king_originala (+1) (mixed 3)
// <<< native-status | src bf8134f9 | roc native-status --write
#include "humanoid/HumanoidStates2.h"
#include "humanoid/Humanoid.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/Controller.h"

namespace RBX {
namespace HUMAN {

const char sFreefall[] = "Freefall";
const char sFlying[] = "Flying";
const char sJumping[] = "Jumping";
const char sGettingUp[] = "GettingUp";

Freefall::Freefall(Humanoid* humanoid)
    : Base(humanoid, 300.0f, 50.0f), torsoFriction(0.0f), headFriction(0.0f)
{
    Humanoid::event_FreeFalling.fire(humanoid, true);
    if (humanoid->getHead()) {
        headFriction = humanoid->getHead()->getFriction();
        humanoid->getHead()->setFriction(0.0f);
    }
    if (humanoid->getTorso()) {
        torsoFriction = humanoid->getTorso()->getFriction();
        humanoid->getTorso()->setFriction(0.0f);
    }
}

Freefall::~Freefall()
{
    Humanoid::event_FreeFalling.fire(getHumanoid(), false);
    if (getHumanoid()->getHead()) {
        Humanoid* owner = getHumanoid();
        owner->getHead()->setFriction(headFriction);
    }
    if (getHumanoid()->getTorso()) {
        Humanoid* owner = getHumanoid();
        owner->getTorso()->setFriction(torsoFriction);
    }
}

void Freefall::onStep(float dt, Controller* controller)
{
    desiredYRotationalVelocity = controller->getValue(Controller::RIGHT_LEFT_INPUT) * 6.0f;
    desiredVelocity = computeWalkVelocity();
}

// Jumping's constructor 00667c40 calls 006674b0 and its onComputeForce 00667a40 calls 0070bdf0:
// Flying was a separate translation unit in the original. noinline keeps that boundary here.
__declspec(noinline) Flying::Flying(Humanoid* humanoid)
    : Base(humanoid, 300.0f, 50.0f)
{
}

__declspec(noinline) void Flying::onComputeForce(float dt)
{
}

Jumping::Jumping(Humanoid* humanoid)
    : Base(humanoid)
{
    value0c = 0.5f;
    Humanoid::event_Jumping.fire(humanoid, true);
}

Jumping::~Jumping()
{
    Humanoid::event_Jumping.fire(getHumanoid(), false);
}

#ifdef NATIVE_HUMANOID_FORCE_PENDING
// Freefall::onComputeForce 006675d0 (514 bytes) and Jumping::onComputeForce 00667a40 (337 bytes): drafts, not compiled.
// BLOCKED on the same header proposals as native-classes/RunningBaseForce.cpp (RunningBase::onComputeForce 00666550):
//   1. v8kernel/Body2008.h: inline Body members getBranchTorque (0062e2e0-shaped: root->simBody ? simBody +0x90 :
//      the Vector3 zero static 0096f044 under guard 0096f050), getBranchForce 0062e2a0 (root->simBody ? simBody +0x84 :
//      the same static), the branch velocity (root->simBody ? simBody +0x3c : static Velocity 0097d568, Velocity()
//      00614170 under guard 0097d580) and accumulateForceAtBranchCofm 0062e140 (SimBody update 00658d20 when dirty
//      +0x8, then force +0x84 += f).
//   2. humanoid/HumanoidState.h: `Primitive* getFloorPrimitive() const; // 00643d30` (floorPart +0x24 ? +0x228 : 0).
//   3. humanoid/Humanoid2008.h: `Body* getRootBody(); // 005d9180` (torso 005d8b10 -> body +0x2c8 -> root +0x10),
//      reachable next to Body2008.h (this unit's v8datamodel/PartInstance.h pulls the donor v8kernel/Body.h: C2011).
// Freefall also reads the writable .data float 00962aa8 (120000.0f, no symbol): the yaw-acceleration limit gain.
// No compile trial was run (no unregistered scratch headers); 0 trials, 0 rejected variants.
// 006675d0: Balancing::onComputeForce 0066e6a0; getRootBody 005d9180; Cofm::getMoment 00660170 or Body::moment
// +0x68 copied (Matrix3::operator= 00513220) into Math::toDiagonal 005ddbb0 (twice); updatePV 00599360 then
// pv.velocity.rotational.y +0xd4; 7500.0f [0084ce84]; G3D::clamp inline; Body::accumulateTorque 006060b0 (0, t, 0);
// desiredVelocity +0xb4 minus branch velocity, * 1250.0f [00847b94], Vector3::clamp 004a6100 (maxMoveForce 00666350
// evaluated before minMoveForce 006663a0), times the branch mass (Cofm::getMass 0065ff10 or mass +0x8c), y = 0,
// accumulateForceAtBranchCofm 0062e140.
extern float freefallYawLimitGain;                       // 00962aa8 (analog name; .data, 120000.0f)

void Freefall::onComputeForce(float dt)
{
    Balancing::onComputeForce(dt);
    Body* body = getHumanoid()->getRootBody();
    if (!body)
        return;
    float torqueY = (desiredYRotationalVelocity - body->getVelocity().rotational.y)
        * Math::toDiagonal(body->getBranchIBody()).y * 7500.0f;
    torqueY -= body->getBranchTorque().y;
    float maxTorqueY = Math::toDiagonal(body->getBranchIBody()).y * freefallYawLimitGain;
    body->accumulateTorque(G3D::Vector3(0.0f, G3D::clamp(torqueY, -maxTorqueY, maxTorqueY), 0.0f));
    G3D::Vector3 accel = (desiredVelocity - body->getBranchVelocity().linear) * 1250.0f;
    G3D::Vector3 clamped = accel.clamp(minMoveForce(), maxMoveForce());
    float mass = body->getBranchMass();
    body->accumulateForceAtBranchCofm(G3D::Vector3(clamped.x * mass, 0.0f, clamped.z * mass));
}

// 00667a40: Flying::onComputeForce 0070bdf0 called directly; flag11 (+0x11) set when there is no root body or the
// jump velocity (50.0f [0084ced4] - pv.velocity.linear.y +0xc8) * 5000.0f [0084ced0] is not positive. With a floor
// primitive (00643d30 called twice): floor root = primitive body +0xa0 -> root +0x10; std::min of the two branch
// masses (the floor's evaluated first, ties keep the torso root's); the needed lift above getBranchForce().y goes to
// accumulateForceAtBranchCofm 0062e140, the negated lift to the floor root (inline Body::accumulateForce:
// root->simBody, SimBody::accumulateForce 00612fb0) at floorTouchInWorld +0x2c.
void Jumping::onComputeForce(float dt)
{
    Flying::onComputeForce(dt);
    if (flag11)
        return;
    Body* body = getHumanoid()->getRootBody();
    if (body) {
        float jumpForce = (50.0f - body->getVelocity().linear.y) * 5000.0f;
        if (jumpForce > 0.0f) {
            if (getFloorPrimitive()) {
                Body* floorRoot = getFloorPrimitive()->getBody()->getRoot();
                float lift = std::min(body->getBranchMass(), floorRoot->getBranchMass()) * jumpForce;
                const G3D::Vector3& current = body->getBranchForce();
                if (lift > current.y) {
                    float delta = lift - current.y;
                    body->accumulateForceAtBranchCofm(G3D::Vector3(0.0f, delta, 0.0f));
                    floorRoot->accumulateForce(G3D::Vector3(0.0f, -delta, 0.0f), floorTouchInWorld);
                }
            }
            return;
        }
    }
    flag11 = true;
}
#endif

GettingUp::GettingUp(Humanoid* humanoid)
    : Base(humanoid, 5000.0f, 300.0f)
{
    Humanoid::event_GettingUp.fire(getHumanoid(), true);
}

GettingUp::~GettingUp()
{
    Humanoid::event_GettingUp.fire(getHumanoid(), false);
}

}
template<> const Name& Named<HUMAN::Balancing, HUMAN::sFreefall>::getName() const { return Name::declare<HUMAN::sFreefall>(); }
template<> const Name& Named<HUMAN::Balancing, HUMAN::sFlying>::getName() const { return Name::declare<HUMAN::sFlying>(); }
template<> const Name& Named<HUMAN::Flying, HUMAN::sJumping>::getName() const { return Name::declare<HUMAN::sJumping>(); }
template<> const Name& Named<HUMAN::Balancing, HUMAN::sGettingUp>::getName() const { return Name::declare<HUMAN::sGettingUp>(); }
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Reflection::SignalDescImpl<1,void __cdecl(bool)>;

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::HUMAN::sFlying>();
template void RBX::Name::callDoDeclare<RBX::HUMAN::sFreefall>();
template void RBX::Name::callDoDeclare<RBX::HUMAN::sJumping>();
template void RBX::Name::callDoDeclare<RBX::HUMAN::sGettingUp>();

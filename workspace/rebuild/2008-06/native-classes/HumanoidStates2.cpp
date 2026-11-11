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

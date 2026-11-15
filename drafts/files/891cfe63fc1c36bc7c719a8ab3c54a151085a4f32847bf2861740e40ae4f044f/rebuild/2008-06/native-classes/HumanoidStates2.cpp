// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
// Inactive native Freefall/Flying/Jumping/GettingUp methods (2008-06). Not in any build list.
// Bodies that read the stored humanoid call the out-of-line getter 00793d50 (HumanoidState::getHumanoid).
// >>> native-status (generated) -- do not edit >>>
// HumanoidStates2 | 2008-06 | draft (no current byte proof)
// 0/5 mapped addresses byte-exact | 5 unproved | no mapped strings | by king_originala (+1) (mixed 3)
// <<< native-status | src bf8134f9 | roc native-status --write
// Batch 15: the part-embedded PartInstance.h with NATIVE_PRIMITIVE_NATIVE_BODY (the HumanoidCamera.cpp context) reaches
// native-headers/v8kernel/Body2008.h instead of the donor v8kernel/Body.h, so the constructors (getFriction 00598d50 /
// setFriction 0059e090) and the Body2008 force bodies Freefall::onComputeForce 006675d0 / Jumping::onComputeForce
// 00667a40 share this unit again. The Humanoid base takes the unit-local Connector (Connector2008.h reaches the donor
// Body.h), exactly as native-headers/v8kernel/Connector2008.h declares it; no Humanoid vtable is emitted here.
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "util/NativeContentProvider.h"
#include "v8datamodel/PartInstance.h"
#include "v8kernel/KernelIndex.h"

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
#include "humanoid/HumanoidStates2.h"
#include "v8world/Controller.h"
#include "AppUnit664/HumanoidForceLimits.h"
#include <G3D/g3dmath.h>
#include <algorithm>

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
// Batch 14 (three more rejected, kept body unchanged): (a) `iBody = body->getBranchIBodyV3()` and getBranchIBodyV3().y
// for the limit -> 515 bytes, frame still 0x60, gain/limit fmul operands swapped; (b) a float local
// `iBodyY = Math::toDiagonal(...).y` -> 521 bytes, frame 0x54 (as the target) but .y copied to a float spill; (c)
// `Math::toDiagonal(...).y * (desired - rotational.y) * 7500` -> 513 bytes, frame and slots as the target, but updatePV
// 00599360 runs between the moment copy and toDiagonal and .y is read from [eax + 4]. The target shares one Vector3 temp
// for both toDiagonal results (both read from [esp + 0x1c] / +0x24) and finishes toDiagonal before updatePV.
extern float freefallYawLimitGain;                       // 00962aa8 (analog name)

// 006675d0
void Freefall::onComputeForce(float dt)
{
    Balancing::onComputeForce(dt);
    Body* body = getHumanoid()->getRootBody();
    if (!body)
        return;
    float torqueY;
    {
        G3D::Vector3 iBody = Math::toDiagonal(body->getBranchIBody());
        torqueY = (desiredYRotationalVelocity - body->getVelocity().rotational.y) * iBody.y * 7500.0f;
    }
    torqueY -= body->getBranchTorque().y;
    float maxTorqueY;
    {
        G3D::Vector3 iBody = Math::toDiagonal(body->getBranchIBody());
        maxTorqueY = iBody.y * freefallYawLimitGain;
    }
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

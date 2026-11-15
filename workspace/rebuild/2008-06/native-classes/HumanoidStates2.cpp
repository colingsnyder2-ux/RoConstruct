// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
// Inactive native Freefall/Flying/Jumping/GettingUp methods (2008-06). Not in any build list.
// Bodies that read the stored humanoid call the out-of-line getter 00793d50 (HumanoidState::getHumanoid).
// Batch 15: the part-embedded PartInstance.h with NATIVE_PRIMITIVE_NATIVE_BODY (the HumanoidCamera.cpp context) reaches
// native-headers/v8kernel/Body2008.h instead of the donor v8kernel/Body.h, so the constructors (getFriction 00598d50 /
// setFriction 0059e090) and the Body2008 force body Freefall::onComputeForce 006675d0 share this unit again. The
// Humanoid base takes the unit-local Connector (Connector2008.h reaches the donor Body.h), exactly as
// native-headers/v8kernel/Connector2008.h declares it; no Humanoid vtable is emitted here.
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

// Freefall::onComputeForce 006675d0 (moved back from RunningBaseForce.cpp in batch 15; this unit now reaches Body2008.h).
// It inlines the Body branch getters (moment copy 00513220 + Math::toDiagonal 005ddbb0, branch torque +0x90 / static
// zero 0096f044 under guard 0096f050, branch velocity +0x3c / static 0097d568, branch mass), and calls accumulateTorque
// 006060b0 and accumulateForceAtBranchCofm 0062e140 out of line.
// 00962aa8: writable .data float 120000.0f without a symbol; the yaw-torque limit gain.
// PARKED near miss (515 bytes against 514). Batch 15 kept form: each toDiagonal result is a named local in its own block,
// so both share one stack Vector3 (the target reads .y from [esp + 0x1c] / [esp + 0x24] for both) and the frame is
// sub esp 0x54 as in the target (the batch-13 form, one function-scope iBody plus a temporary, had 0x60 and read the
// second .y through [eax + 4]). Remaining differences: the limit product loads the gain first (`fld [00962aa8]; fmul
// [esp + 0x24]`, target `fld [esp + 0x24]; fmul [gain]`), G3D::clamp pops st(2) instead of st(0), Vector3::clamp's
// arguments are pushed as each of maxMoveForce 00666350 / minMoveForce 006663a0 returns (target: max result kept in edi,
// both pushed after the second call), and the final (x * mass, 0, z * mass) stores 0 before z. The last two were already
// present in the batch-13 form.
// Rejected: batch 13 (1) both toDiagonal calls inline in the expressions -> 513 bytes, updatePV 00599360 before the
// first moment copy; (2) one named iBody assigned twice -> three-float copy of the second result. Batch 14 (a)
// getBranchIBodyV3() for both -> 515 bytes, frame 0x60; (b) a float local `iBodyY = Math::toDiagonal(...).y` -> 521
// bytes, .y copied to a float spill; (c) `Math::toDiagonal(...).y * (desired - rotational.y) * 7500` -> 513 bytes,
// updatePV between the moment copy and toDiagonal. Batch 15 (d) `freefallYawLimitGain * iBody.y` -> identical output.
// Jumping::onComputeForce 00667a40 stays in RunningBaseForce.cpp: it calls Flying::onComputeForce 0070bdf0 directly,
// and with Flying's empty body visible in this unit the compiler drops that call (batch 15 trial: 322 bytes, no call).
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

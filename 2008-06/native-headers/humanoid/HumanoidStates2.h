#pragma once
// >>> native-status (generated) -- do not edit >>>
// HumanoidStates2 | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src ced97750 | roc native-status --write
#include "humanoid/HumanoidStates1.h"
#include "util/Name.h"
#include <G3D/Vector3.h>

namespace RBX {
namespace HUMAN {
// Inactive native layouts of the 2008-06 humanoid states Freefall, Flying, Jumping and
// GettingUp. Do not instantiate or use in the running player. Balancing (the shared
// intermediate base, kP +0xa0 / kD +0xa4, ctor 0066e660) comes from HumanoidStates1.h.
// Member names are analog names, not original declarations.
//
// Named<> template arguments: RTTI spells them $1?sFreefall@23@3QBDB etc. (const char arrays);
// the Name::doDeclare<> instantiations 00667560/00667430/00667ba0/00667d80 read them.
extern const char sFreefall[];                           // 0084ce88 "Freefall"
extern const char sFlying[];                             // 0084ce40 "Flying"
extern const char sJumping[];                            // 0084ced8 "Jumping"
extern const char sGettingUp[];                          // 0084cf18 "GettingUp"

// Freefall : Named<Balancing, sFreefall> (RTTI .?AVFreefall@HUMAN@RBX@@, 6 bases).
// - primary vtable 0084cea0, HitTestFilter vtable 0084ce98 (filterResult 006432e0 inherited).
// - constructor 00667810: Balancing(humanoid, 300.0f [0084cc5c], 50.0f [00819ba4]); zero
//   floats +0xac, +0xb0, +0xb4..+0xbc (+0xa8 is not initialized); fires
//   Humanoid::event_FreeFalling(true); saves head friction (PartInstance::getFriction
//   00598d50) to +0xb0 and torso friction to +0xac, then sets both parts' friction to 0
//   (PartInstance::setFriction 0059e090).
// - destructor 00667930 fires event_FreeFalling(false) and restores +0xb0 (head) and +0xac
//   (torso); deleting destructor 00667a20. Allocation size 0xc0 (factory 00643660).
// - onStep 00667510 stores controller->getValue(RIGHT_LEFT_INPUT) * 6.0f [0084ce80] at +0xa8
//   and the computeWalkVelocity() result at +0xb4..+0xbc.
// - onComputeForce 006675d0 calls Balancing::onComputeForce 0066e6a0 and reads +0xa8 and
//   +0xb4..+0xbc (Body/Cofm/SimBody layouts pending).
// - slots 3/4 0060a2f0 (return false), slot 5 inherited (true), getStateType 3 (005e2790).
class Freefall : public Named<Balancing, sFreefall> {
public:
    float desiredYRotationalVelocity;                    // +0xa8
    float torsoFriction;                                 // +0xac
    float headFriction;                                  // +0xb0
    G3D::Vector3 desiredVelocity;                        // +0xb4

    Freefall(Humanoid* humanoid);                        // 00667810
    virtual ~Freefall();                                 // 00667930, deleting 00667a20
    virtual void onStep(float dt, Controller* controller); // slot 1, 00667510
    virtual int getStateType() const { return 3; }       // slot 2, 005e2790 (folded)
    virtual bool query3() const { return false; }        // slot 3, 0060a2f0 (folded)
    virtual bool query4() const { return false; }        // slot 4, 0060a2f0 (folded)
    virtual void onComputeForce(float dt);               // slot 8, 006675d0 (pending)
};

// Flying : Named<Balancing, sFlying> (RTTI .?AVFlying@HUMAN@RBX@@).
// - primary vtable 0084ce54, HitTestFilter vtable 0084ce4c.
// - constructor 006674b0: Balancing(humanoid, 300.0f, 50.0f) and the two vptr stores only.
//   Allocation size 0xa8 (factory 00643660). Slot 6 is the base's deleting destructor
//   00643d10 (implicit destructor, identical code).
// - slot 8 is 0070bdf0 (ret 4): Flying replaces Balancing::onComputeForce with an empty body;
//   Jumping's onComputeForce 00667a40 calls it directly. getStateType 4 (006fa3f0).
class Flying : public Named<Balancing, sFlying> {
public:
    Flying(Humanoid* humanoid);                          // 006674b0
    virtual int getStateType() const { return 4; }       // slot 2, 006fa3f0 (folded)
    virtual void onComputeForce(float dt);               // slot 8, 0070bdf0 (folded empty)
};

// Jumping : Named<Flying, sJumping> (RTTI .?AVJumping@HUMAN@RBX@@, 8 bases).
// - primary vtable 0084ceec, HitTestFilter vtable 0084cee4.
// - constructor 00667c40: Flying(humanoid) 006674b0, value0c = 0.5f [00819bac], fires
//   Humanoid::event_Jumping(true). Allocation size 0xa8 (no members of its own).
// - destructor 00667cd0 fires event_Jumping(false); deleting destructor 00667d60.
// - onComputeForce 00667a40 calls Flying::onComputeForce, tests flag11 and uses Body/Cofm/
//   SimBody (pending). Slots 3/4 return false, getStateType 2 (0077d810).
class Jumping : public Named<Flying, sJumping> {
public:
    Jumping(Humanoid* humanoid);                         // 00667c40
    virtual ~Jumping();                                  // 00667cd0, deleting 00667d60
    virtual int getStateType() const { return 2; }       // slot 2, 0077d810 (folded)
    virtual bool query3() const { return false; }        // slot 3, 0060a2f0 (folded)
    virtual bool query4() const { return false; }        // slot 4, 0060a2f0 (folded)
    virtual void onComputeForce(float dt);               // slot 8, 00667a40 (pending)
};

// GettingUp : Named<Balancing, sGettingUp> (RTTI .?AVGettingUp@HUMAN@RBX@@).
// - primary vtable 0084cf30, HitTestFilter vtable 0084cf28.
// - constructor 00667e20: Balancing(humanoid, 5000.0f [00826de0], 300.0f [0084cc5c]), fires
//   Humanoid::event_GettingUp(true) through the stored humanoid. Allocation size 0xa8.
// - destructor 00667ec0 fires event_GettingUp(false); deleting destructor 00667f50.
// - slot 8 inherited from Balancing (0066e6a0); slots 3/4 return false; getStateType 1 (007286a0).
class GettingUp : public Named<Balancing, sGettingUp> {
public:
    GettingUp(Humanoid* humanoid);                       // 00667e20
    virtual ~GettingUp();                                // 00667ec0, deleting 00667f50
    virtual int getStateType() const { return 1; }       // slot 2, 007286a0 (folded)
    virtual bool query3() const { return false; }        // slot 3, 0060a2f0 (folded)
    virtual bool query4() const { return false; }        // slot 4, 0060a2f0 (folded)
};
}
}

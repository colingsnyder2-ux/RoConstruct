#pragma once
// >>> native-status (generated) -- do not edit >>>
// HumanoidStates1 | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 7dbcf467 | roc native-status --write
#include "humanoid/HumanoidState.h"
#include "util/Name.h"

namespace RBX {
namespace HUMAN {
// Inactive native layouts of the 2008-06 Balancing/RunningBase humanoid states and
// the Named<RunningBase> leaves Running, Landed and Climbing. Do not instantiate or
// use in the running player. Member names are analog names, not original declarations.

// Balancing (RTTI .?AVBalancing@HUMAN@RBX@@: HumanoidState at +0, HitTestFilter at +4).
// - primary vtable 0084d0dc, HitTestFilter vtable 0084d0d4 (filterResult 006432e0 inherited).
// - constructor 0066e660 (thiscall, ret 0xc): calls HumanoidState(Humanoid*) 00643e00,
//   stores the two float arguments at +0xa0 and +0xa4.
// - slot 6 is the base's scalar deleting destructor 00643d10 (implicit destructor).
// - slot 8 0066e6a0 overrides onComputeForce and reads +0xa0 (negated, torque gain) and
//   +0xa4 (scales the angular-velocity term).
// Shared intermediate base for Freefall, Flying, Jumping and GettingUp (other groups).
class Balancing : public HumanoidState {
public:
    const float kP;                                      // +0xa0
    const float kD;                                      // +0xa4

    Balancing(Humanoid* humanoid, float kP, float kD);   // 0066e660
    virtual void onComputeForce(float dt);               // slot 8, 0066e6a0 (pending: Body layout)
};

// RunningBase (RTTI .?AVRunningBase@HUMAN@RBX@@ : Balancing).
// - primary vtable 0084cc38, HitTestFilter vtable 0084cc30.
// - constructor 00666980 calls Balancing(humanoid, 300.0f [0084cc5c], 50.0f [00819ba4]),
//   zeroes the nine floats +0xa8..+0xc8 and fires Humanoid::event_Running (0097a504) with 0.
// - destructor 006663f0 (vptr stores, then ~HumanoidState); deleting destructor 00666520.
// - onStep 00666410 stores +0xc8 (00643360 result), Vector3 +0xa8 and float +0xb4 (linear and
//   rotational.y of the Velocity returned by 00643a70), Vector3 +0xb8 (computeWalkVelocity) and +0xc4 = 0.
// - slots 3/4 return false (0060a2f0); slot 7 00643400 returns +0xc4. Allocation size of the leaves is 0xcc (factory 00643660).
class RunningBase : public Balancing {
public:
    G3D::Vector3 floorVelocity;                          // +0xa8
    float floorRotationalVelocity;                       // +0xb4
    G3D::Vector3 desiredVelocity;                        // +0xb8
    float desiredYRotation;                              // +0xc4
    float desiredAltitude;                               // +0xc8

    RunningBase(Humanoid* humanoid);                     // 00666980
    virtual ~RunningBase();                              // 006663f0, deleting 00666520
    virtual void onStep(float dt, Controller* controller); // slot 1, 00666410 (pending)
    virtual bool query3() const { return false; }        // slot 3, 0060a2f0 (folded)
    virtual bool query4() const { return false; }        // slot 4, 0060a2f0 (folded)
    virtual float getIntendedRotationAboutYAxis() const; // slot 7, 00643400
    virtual void onComputeForce(float dt);               // slot 8, 00666550 (pending)
};

// Named<RunningBase, sX> template arguments (RTTI $1?sRunning@23@3QBDB etc.).
extern const char sRunning[];                            // 0084cc68 "Running"
extern const char sLanded[];                             // 0084cc70 "Landed"
extern const char sClimbing[];                           // 0084cc78 "Climbing"

// Running : Named<RunningBase, sRunning>. vtable 0084cc94/0084cc8c, ctor 00666ac0
// (value0c = 0.25f [0084cc84]), getName 00666b00, onStep 00666b20, getStateType 6 (005cb9d0).
class Running : public Named<RunningBase, sRunning> {
public:
    Running(Humanoid* humanoid);                         // 00666ac0
    virtual void onStep(float dt, Controller* controller); // slot 1, 00666b20
    virtual int getStateType() const { return 6; }       // slot 2, 005cb9d0 (folded)
};

// Landed : Named<RunningBase, sLanded>. vtable 0084ac9c/0084ac94, ctor 00643550
// (value0c = 0.45f [0084acc0]), getName 00643ed0, onStep inherited (00666410),
// getStateType 5 (007359e0).
class Landed : public Named<RunningBase, sLanded> {
public:
    Landed(Humanoid* humanoid);                          // 00643550
    virtual int getStateType() const { return 5; }       // slot 2, 007359e0 (folded)
};

// Climbing : Named<RunningBase, sClimbing>. vtable 0084acd0/0084acc8, ctor 006435a0,
// getName 00643ef0, onStep 00666bc0 (fires event_Climbing 0097a58c), getStateType 9 (0064cac0).
class Climbing : public Named<RunningBase, sClimbing> {
public:
    Climbing(Humanoid* humanoid);                        // 006435a0
    virtual void onStep(float dt, Controller* controller); // slot 1, 00666bc0
    virtual int getStateType() const { return 9; }       // slot 2, 0064cac0 (folded)
};
}
}

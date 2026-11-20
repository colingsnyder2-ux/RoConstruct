#pragma once
#include "humanoid/HumanoidState.h"
#include "util/Name.h"

namespace RBX {
namespace HUMAN {

class Balancing : public HumanoidState {
public:
    const float kP;                                      // +0xa0
    const float kD;                                      // +0xa4

    Balancing(Humanoid* humanoid, float kP, float kD);   // 0066e660
    virtual void onComputeForce(float dt);               // slot 8, 0066e6a0 (pending: Body layout)
};

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

extern const char sRunning[];                            // 0084cc68 "Running"
extern const char sLanded[];                             // 0084cc70 "Landed"
extern const char sClimbing[];                           // 0084cc78 "Climbing"

class Running : public Named<RunningBase, sRunning> {
public:
    Running(Humanoid* humanoid);                         // 00666ac0
    virtual void onStep(float dt, Controller* controller); // slot 1, 00666b20
    virtual int getStateType() const { return 6; }       // slot 2, 005cb9d0 (folded)
};

class Landed : public Named<RunningBase, sLanded> {
public:
    Landed(Humanoid* humanoid);                          // 00643550
    virtual int getStateType() const { return 5; }       // slot 2, 007359e0 (folded)
};

class Climbing : public Named<RunningBase, sClimbing> {
public:
    Climbing(Humanoid* humanoid);                        // 006435a0
    virtual void onStep(float dt, Controller* controller); // slot 1, 00666bc0
    virtual int getStateType() const { return 9; }       // slot 2, 0064cac0 (folded)
};
}
}

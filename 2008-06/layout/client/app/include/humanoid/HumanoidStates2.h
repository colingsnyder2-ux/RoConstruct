// =============================================================================
// HumanoidStates2.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/humanoid/HumanoidStates2.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "humanoid/HumanoidStates1.h"
#include "util/Name.h"
#include <G3D/Vector3.h>

namespace RBX
{
namespace HUMAN
{
extern const char sFreefall[];                           // 0084ce88 "Freefall"
extern const char sFlying[];                             // 0084ce40 "Flying"
extern const char sJumping[];                            // 0084ced8 "Jumping"
extern const char sGettingUp[];                          // 0084cf18 "GettingUp"

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

class Flying : public Named<Balancing, sFlying> {
public:
    Flying(Humanoid* humanoid);                          // 006674b0
    virtual int getStateType() const { return 4; }       // slot 2, 006fa3f0 (folded)
    virtual void onComputeForce(float dt);               // slot 8, 0070bdf0 (folded empty)
};

class Jumping : public Named<Flying, sJumping> {
public:
    Jumping(Humanoid* humanoid);                         // 00667c40
    virtual ~Jumping();                                  // 00667cd0, deleting 00667d60
    virtual int getStateType() const { return 2; }       // slot 2, 0077d810 (folded)
    virtual bool query3() const { return false; }        // slot 3, 0060a2f0 (folded)
    virtual bool query4() const { return false; }        // slot 4, 0060a2f0 (folded)
    virtual void onComputeForce(float dt);               // slot 8, 00667a40 (pending)
};

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

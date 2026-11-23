// =============================================================================
// HumanoidStates3SimJob.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/humanoid/HumanoidStates3SimJob.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "v8world/SimJob.h"
#include <boost/signals/connection.hpp>

namespace RBX
{
class PhysicsService;
namespace HUMAN
{

#include <boost/signals/connection.hpp>

extern const char sMovingNoPhysicsBase[];                // 0084d108 "MovingNoPhysicsBase"
extern const char sRunningNoPhysics[];                   // 0084cde0 "RunningNoPhysics"
extern const char sStrafingNoPhysics[];                  // 0084cd80 "StrafingNoPhysics"

class MovingNoPhysicsBase : public Named<HumanoidState, sMovingNoPhysicsBase>, public SimJob {
public:
    boost::shared_ptr<PartInstance> torso;               // +0xc4
    PhysicsService* physicsService;                      // +0xcc
    boost::signals::scoped_connection connection;        // +0xd0
    G3D::CoordinateFrame frame;                          // +0xe4

    MovingNoPhysicsBase(Humanoid* humanoid);             // 0066f070 (pending)
    virtual ~MovingNoPhysicsBase();                      // 0066ee10, deleting 00667410
    virtual void onStep(float dt, Controller* controller); // slot 1, 0066f2c0 (pending)
    virtual int getStateType() const { return 7; }       // slot 2, 0077d800
    virtual bool query3() const { return false; }        // slot 3, 0060a2f0 (folded)
    virtual bool query4() const { return false; }        // slot 4, 0060a2f0 (folded)
    virtual bool query5() const { return false; }        // slot 5, 0060a2f0 (folded)
    virtual Assembly* getAssembly();                     // SimJob slot 1, 00667160
    virtual Assembly* getAssembly2();                    // SimJob slot 2, 00667160 (identical code)
    Assembly* getTorsoAssembly();                        // 0066eaa0
    void release();                                      // 0066ed50 (pending: World layout)
};

class RunningNoPhysics : public Named<MovingNoPhysicsBase, sRunningNoPhysics> {
public:
    RunningNoPhysics(Humanoid* humanoid);                // 00667370
    virtual void onStep(float dt, Controller* controller); // slot 1, 006672b0
};

class StrafingNoPhysics : public Named<MovingNoPhysicsBase, sStrafingNoPhysics> {
public:
    StrafingNoPhysics(Humanoid* humanoid);               // 00667210
    virtual void onStep(float dt, Controller* controller); // slot 1, 006672b0 (folded)
    virtual int getStateType() const { return 8; }       // slot 2, 0063e420
};
}
}

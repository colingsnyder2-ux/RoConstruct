#pragma once
#include "humanoid/HumanoidState.h"
#include "util/Name.h"

namespace RBX {
namespace HUMAN {
// Inactive native layouts of the 2008-06 humanoid states Seated, Dead, FallingDown and the
// MovingNoPhysicsBase family (RunningNoPhysics, StrafingNoPhysics). Do not instantiate or use
// in the running player. Member names are analog names, not original declarations.
//
// Named<> template arguments: RTTI spells them $1?sSeated@23@3QBDB etc. (const char arrays);
// the Name::doDeclare<> instantiations below read them.
extern const char sSeated[];                             // 0084cd40 "Seated"
extern const char sDead[];                               // 0084cccc "Dead"
extern const char sFallingDown[];                        // 0084ccc0 "FallingDown"

// Seated : Named<HumanoidState, sSeated> (RTTI .?AVSeated@HUMAN@RBX@@, 5 bases).
// - primary vtable 0084cd54, HitTestFilter vtable 0084cd4c (filterResult 006432e0 inherited).
// - constructor 00667010: HumanoidState(humanoid), fires Humanoid::event_Seated(true)
//   (descriptor 0097a558, name "Seated") through the argument, then setLimbFlag(true).
// - destructor 006670b0 fires event_Seated(false) through the out-of-line humanoid getter
//   00793d50; deleting destructor 00667140. Allocation size 0xa0 (factory 00643660).
// - onStep inherited (00458e90); slots 3/4 return false (0060a2f0), slot 5 true;
//   getStateType 10 (006670a0).
class Seated : public Named<HumanoidState, sSeated> {
public:
    Seated(Humanoid* humanoid);                          // 00667010
    virtual ~Seated();                                   // 006670b0, deleting 00667140
    virtual int getStateType() const { return 10; }      // slot 2, 006670a0
    virtual bool query3() const { return false; }        // slot 3, 0060a2f0 (folded)
    virtual bool query4() const { return false; }        // slot 4, 0060a2f0 (folded)
};

// Dead : Named<HumanoidState, sDead> (RTTI .?AVDead@HUMAN@RBX@@).
// - primary vtable 0084cce0, HitTestFilter vtable 0084ccd8.
// - constructor 00666d30: HumanoidState(humanoid), then
//   Humanoid::getCharacterFromHumanoid(humanoid) 005d7670 and, when non-null,
//   ModelInstance::breakJoints 00584c00.
// - empty inline destructor: the deleting destructor 00666da0 stores the two vptrs and
//   calls ~HumanoidState 006435c0 (an implicit destructor skips the vptr stores). Allocation size 0xa0. Slots 3..5 keep true;
//   getStateType 11 (00666c40).
class Dead : public Named<HumanoidState, sDead> {
public:
    Dead(Humanoid* humanoid);                            // 00666d30
    virtual ~Dead() {}                                   // inlined into deleting 00666da0
    virtual int getStateType() const { return 11; }      // slot 2, 00666c40
};

// FallingDown : Named<HumanoidState, sFallingDown> (RTTI .?AVFallingDown@HUMAN@RBX@@).
// - primary vtable 0084cd10, HitTestFilter vtable 0084cd08.
// - constructor 00666e30: HumanoidState(humanoid), fires event_FallingDown(true)
//   (descriptor 0097a2f4, name "FallingDown") through the humanoid getter 00793d50,
//   then value0c = 3.0f [0081e380].
// - destructor 00666ec0 fires event_FallingDown(false); deleting destructor 00666f50.
//   Allocation size 0xa0 (no members of its own). Slots 3..5 keep true;
//   getStateType 0 (00416690, xor eax,eax).
class FallingDown : public Named<HumanoidState, sFallingDown> {
public:
    FallingDown(Humanoid* humanoid);                     // 00666e30
    virtual ~FallingDown();                              // 00666ec0, deleting 00666f50
    virtual int getStateType() const { return 0; }       // slot 2, 00416690 (folded)
};
}
}

#ifdef NATIVE_SIMJOB_PENDING
// RBX::SimJob has no native header. tests/NativeHumanoidStates3SimJob.h is the proposed
// declaration (vptr, boost::noncopyable, std::vector at +4, std::list iterator at +0x1c;
// sizeof 0x24, constructor 005e50f0, destructor 005e5150). The recorder places it at
// v8world/SimJob.h in its overlay.
#include "v8world/SimJob.h"
#include <boost/signals/connection.hpp>

namespace RBX {
class PhysicsService;
namespace HUMAN {
extern const char sMovingNoPhysicsBase[];                // 0084d108 "MovingNoPhysicsBase"
extern const char sRunningNoPhysics[];                   // 0084cde0 "RunningNoPhysics"
extern const char sStrafingNoPhysics[];                  // 0084cd80 "StrafingNoPhysics"

// MovingNoPhysicsBase : Named<HumanoidState, sMovingNoPhysicsBase>, SimJob
// (RTTI .?AVMovingNoPhysicsBase@HUMAN@RBX@@, 7 bases: SimJob at +0xa0, its
// boost::noncopyable base at +0xa4).
// - primary vtable 0084d168 (9 slots), HitTestFilter vtable 0084d160, SimJob vtable 0084d150
//   (slot 0 compiler adjustor thunk 00667400 'sub ecx,0xa0; jmp 00667410'; slots 1 and 2 are
//   00667160 'add ecx,-0xa0; jmp 0066eaa0': SimJob overrides that tail-call a nonvirtual helper).
// - constructor 0066f070 (pending): HumanoidState(humanoid), SimJob() 005e50f0, zeroes
//   +0xc4/+0xc8 (shared_ptr), +0xcc, and the scoped_connection +0xd0 (+0xd4/+0xd8 px/pn,
//   +0xdc controlling flag, +0xe0 released flag); CoordinateFrame() 004782d0 at +0xe4;
//   stores shared_from(torso part) in +0xc4, copies its CoordinateFrame to +0xe4, stores
//   the ServiceProvider-created PhysicsService (0066f020, 005e8f70) in +0xcc and the
//   connection result of 004a3340 into +0xd0.
// - destructor 0066ee10: if (+0xc4) 0066ed50; ~scoped_connection 005954b0 (+0xd0);
//   shared_ptr release (+0xc4/+0xc8); inline ~SimJob (vptr 0083f72c, vector +0xb0/+0xa4);
//   ~HumanoidState 006435c0. Deleting destructor 00667410. Allocation size of the leaves 0x114.
// - onStep 0066f2c0 (pending: World/Body layouts) adds to the +0xe4 frame translation
//   (+0x108..+0x110). Slots 3..5 return false; getStateType 7 (0077d800, also inherited
//   by RunningNoPhysics).
// - 0066eaa0 (nonvirtual, this = MovingNoPhysicsBase): getHumanoid()->getTorsoPrimitive()
//   ? ->getAssembly() : 0; both SimJob overrides (00667160, identical code) return it.
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

// RunningNoPhysics : Named<MovingNoPhysicsBase, sRunningNoPhysics> (9 bases).
// - vtables 0084ce10 / 0084ce08 / 0084cdf8; constructor 00667370: MovingNoPhysicsBase(humanoid),
//   then Humanoid::event_Running(0.0f) (0097a504) through the argument.
// - onStep 006672b0 forwards to MovingNoPhysicsBase::onStep 0066f2c0 (also StrafingNoPhysics'
//   slot 1: identical code). getStateType inherited (7). Implicit destructor: slot 6 is
//   00667410 (identical code to MovingNoPhysicsBase's deleting destructor).
class RunningNoPhysics : public Named<MovingNoPhysicsBase, sRunningNoPhysics> {
public:
    RunningNoPhysics(Humanoid* humanoid);                // 00667370
    virtual void onStep(float dt, Controller* controller); // slot 1, 006672b0
};

// StrafingNoPhysics : Named<MovingNoPhysicsBase, sStrafingNoPhysics> (9 bases).
// - vtables 0084cdb0 / 0084cda8 / 0084cd98; constructor 00667210: MovingNoPhysicsBase(humanoid),
//   then Humanoid::event_Strafing(false) (0097a348, name "Strafing") through the argument.
// - onStep 006672b0 (identical code), getStateType 8 (0063e420).
class StrafingNoPhysics : public Named<MovingNoPhysicsBase, sStrafingNoPhysics> {
public:
    StrafingNoPhysics(Humanoid* humanoid);               // 00667210
    virtual void onStep(float dt, Controller* controller); // slot 1, 006672b0 (folded)
    virtual int getStateType() const { return 8; }       // slot 2, 0063e420
};
}
}
#endif

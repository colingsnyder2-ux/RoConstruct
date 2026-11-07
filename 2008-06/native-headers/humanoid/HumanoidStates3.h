#include "humanoid/HumanoidState.h"
#include "util/Name.h"
#include "humanoid/HumanoidStates3SimJob.h"
#include "v8world/SimJob.h"

int dummy_preprocess_marker;

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


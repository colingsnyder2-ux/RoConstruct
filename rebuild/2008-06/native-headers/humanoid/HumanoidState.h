#pragma once
#include "util/Name.h"
#include "util/HitTestFilter.h"
#include <boost/shared_ptr.hpp>
#include <G3D/Array.h>
#include <G3D/Vector3.h>
#include <G3D/CoordinateFrame.h>

namespace RBX {
class Humanoid;
class PartInstance;
class Primitive;
class Controller;
class Velocity;
namespace HUMAN {
// Inactive native layout of the 2008-06 HumanoidState base. Do not instantiate
// or use in the running player.
//
// Evidence (2008-06 Roblox.exe):
// - RTTI .?AVHumanoidState@HUMAN@RBX@@: INamed at +0, HitTestFilter at +4.
// - primary vtable 0084ad00 (9 slots), HitTestFilter vtable 0084acf8 (1 slot).
// - constructor 00643e00: stores +0x08 (Humanoid* argument), +0x0c (0.0f),
//   +0x10/+0x11 (false), +0x14/+0x18/+0x1c (G3D::Array data/num/numAllocated),
//   +0x24/+0x28 (shared_ptr px/pn), five zero floats +0x2c..+0x3c, and
//   CoordinateFrame constructor calls at +0x40 and +0x70.
// - destructor 006435c0: shared_ptr release at +0x24/+0x28, then
//   System::alignedFree(+0x14) and +0x14/+0x18/+0x1c = 0 (G3D::Array of a
//   trivially destructible element).
// - 00644a30 passes &array14 to the geometry query 0062db60 and reads each
//   element's +0x104 (Instance::parent), so the elements are PartInstance*.
// - 006451c0 clears +0x20, resets the +0x24 shared_ptr, stores Vector3::inf()
//   at +0x2c and copies 0x30-byte CoordinateFrames +0x70 -> +0x40.
// - 00643b60 moves +0x38 to +0x3c and stores a vector length in +0x38.
// - Subclass storage starts at +0xa0 (MovingNoPhysicsBase SimJob base at
//   +0xa0; Seated/Dead/FallingDown factory allocations are exactly 0xa0).
// Member names after flag11 are analog names, not original declarations.
class HumanoidState : public INamed, public HitTestFilter {
public:
    Humanoid* humanoid;
    float value0c;
    bool flag10;
    bool flag11;
    G3D::Array<PartInstance*> array14;
    bool floorFound;
    boost::shared_ptr<PartInstance> floorPart;
    G3D::Vector3 floorTouchInWorld;
    float speed38;
    float speed3c;
    G3D::CoordinateFrame previous;
    G3D::CoordinateFrame current;

    HumanoidState(Humanoid* humanoid);
    // vtable 0084ad00 slot order: 0 getName (pure, INamed), 1 onStep,
    // 2 getStateType (pure), 3..5 bool queries, 6 scalar deleting destructor,
    // 7 getIntendedRotationAboutYAxis, 8 onComputeForce.
    virtual void onStep(float dt, Controller* controller) {}          // slot 1, 00458e90 ret 8
    virtual int getStateType() const = 0;                             // slot 2 (Seated returns 10)
    virtual bool query3() const { return true; }                      // slot 3, 00565950
    virtual bool query4() const { return true; }                      // slot 4, 00565950
    virtual bool query5() const { return true; }                      // slot 5, 00565950
    virtual ~HumanoidState();                                         // slot 6, 00643d10 / 006435c0
    virtual float getIntendedRotationAboutYAxis() const { return 0.0f; } // slot 7, 005e72c0
    virtual void onComputeForce(float dt) {}                          // slot 8, 0070bdf0 ret 4
    virtual HitTestFilter::Result filterResult(const Primitive* testMe) const; // 006432e0

    // Out of line: callers call the identical-code-folded getter 00793d50 (mov eax,[ecx+8]; ret).
    Humanoid* getHumanoid() const;                                    // 00793d50
    void setLimbFlag(bool value);                                     // 006431b0
    bool speedSettled() const;                                        // 00643330 (callers 00666b20/00666bc0 test al)
    // Base helpers called by RunningBase::onStep 00666410 / Running::onStep 00666b20 (bodies pending;
    // analog names):
    float getDesiredAltitude();                                       // 00643360: plain ret, float on st(0)
    Velocity getFloorVelocity(float dt);                              // 00643a70: hidden return pointer + float, ret 8;
                                                                      //   writes 6 floats (static Velocity::zero() 0097d568 fallback)
    bool onFloorStep();                                               // 006444f0: plain ret, al
    G3D::Vector3 computeWalkVelocity();                               // 00643b60
    void setLegsFlag(bool value);                                     // 00643bc0
    void setArmsFlag(bool value);                                     // 00643c20
    void setTorsoHeadFlag(bool value);                                // 00643c80
};
}
}

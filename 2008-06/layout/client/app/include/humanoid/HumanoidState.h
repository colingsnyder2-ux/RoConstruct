// =============================================================================
// HumanoidState.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/humanoid/HumanoidState.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "util/Name.h"
#include "util/HitTestFilter.h"
#include <boost/shared_ptr.hpp>
#include <G3D/Array.h>
#include <G3D/Vector3.h>
#include <G3D/CoordinateFrame.h>
#include <memory>

namespace G3D
{
class Ray;
}

namespace RBX
{
class Humanoid;
class PartInstance;
class Primitive;
class Controller;
class Velocity;
class Adorn;
namespace HUMAN
{
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
    virtual void onStep(float dt, Controller* controller) {}          // slot 1, 00458e90 ret 8
    virtual int getStateType() const = 0;                             // slot 2 (Seated returns 10)
    virtual bool query3() const { return true; }                      // slot 3, 00565950
    virtual bool query4() const { return true; }                      // slot 4, 00565950
    virtual bool query5() const { return true; }                      // slot 5, 00565950
    virtual ~HumanoidState();                                         // slot 6, 00643d10 / 006435c0
    virtual float getIntendedRotationAboutYAxis() const { return 0.0f; } // slot 7, 005e72c0
    virtual void onComputeForce(float dt) {}                          // slot 8, 0070bdf0 ret 4
    virtual HitTestFilter::Result filterResult(const Primitive* testMe) const; // 006432e0

    Humanoid* getHumanoid() const;                                    // 00793d50
    Primitive* getFloorPrimitive() const;                             // 00643d30: floorPart +0x24 ? part + 0x228 (embedded
                                                                      //   Primitive) : NULL (analog name)
    bool sub_00643eb0() const;   // INFERRED: 00643eb0, placeholder name (identity tier), body byte-proved (Inferred_00643eb0.cpp)
    void render3dAdorn(Adorn* adorn);                                 // 00645060 (thiscall; called by Humanoid::render3dAdorn
    static void stepState(std::auto_ptr<HumanoidState>& state, float dt, Controller* controller);
    // State factories of the HumanoidState unit (cdecl statics; analog names: the registry has placeholders only).
    static HumanoidState* create(int stateType, Humanoid* humanoid);  // 00643660: switch on the getStateType values 0..11
                                                                      //   (FallingDown .. Dead), default Running
    static HumanoidState* createDefault(Humanoid* humanoid);          // 00643280: new Running (Humanoid::onAncestorChanged
    bool canTransition(int event);
    bool tipped() const;   // 00643a30 (analog name): sub-call 006439b0 float compared with 0x82f83c
    bool upright() const;  // 00643a50 (analog name): same float compared with 0x826fc8
    float getRatio() const; // 006439b0 (INFERRED: helper called by tipped/upright)
    void preStep(float dt);
    void findFloor();                                                 // 00644000: plain ret; rays below the torso
    bool findClimbable(Adorn* adorn);                                 // 00644c80: ret 4, al; preStep passes NULL
    boost::shared_ptr<PartInstance> floorPartFromRay(const G3D::Ray& ray, float maxDistance);
    bool climbableInFront(Adorn* adorn);                              // 00644a30: ret 4, al; GeometryService
    static void transition(std::auto_ptr<HumanoidState>& state, float dt);
    static const int transitionTable[][18];                           // 0084a92c (INFERRED: stride 0x48 from asm)
    void setLimbFlag(bool value);                                     // 006431b0
    bool speedSettled() const;                                        // 00643330 (callers 00666b20/00666bc0 test al)
    float getDesiredAltitude();                                       // 00643360: plain ret, float on st(0)
    Velocity getFloorVelocity(float dt);                              // 00643a70: hidden return pointer + float, ret 8;
    bool onFloorStep();                                               // 006444f0: plain ret, al
    G3D::Vector3 computeWalkVelocity();                               // 00643b60
    void setLegsFlag(bool value);                                     // 00643bc0
    void setArmsFlag(bool value);                                     // 00643c20
    void setTorsoHeadFlag(bool value);                                // 00643c80
};
}
}

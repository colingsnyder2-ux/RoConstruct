#pragma once
// Proposed declaration-only overlay for RBX::Humanoid and RBX::Primitive (no layout declared).
// tests/record_native_humanoid_states3.py copies this to out/humanoid-states3-overlay/humanoid/Humanoid.h
// until a native Humanoid header exists; it is not a shared header.
// Evidence: RTTI .?AVHumanoid@RBX@@ lists DescribedCreatable<Humanoid,Instance,sHumanoid> with
// Reflection::SignalSource at +0x14. 00667010/006670b0 (Seated), 00666e30/00666ec0 (FallingDown),
// 00667370 (RunningNoPhysics) and 00667210 (StrafingNoPhysics) pass humanoid ? humanoid+0x14 : 0 to
// SignalDescriptor::findSignalInstance 0056b620 on 0097a558, 0097a2f4, 0097a504 and 0097a348, then
// call boost::signal1<void,bool> 005e1f00 (or <void,float> 004937f0 for Running) on instance+0x10.
// Static initializers 007f6950/007f6930/007f6910 name them "Seated"/"FallingDown"/"Strafing"
// (argument name "active").
#include "v8tree/Instance.h"
#include "reflection/signal.h"
namespace RBX {
// The native v8datamodel/ModelInstance.h pulls the donor Camera.h, which does not compile against
// the native Named<> template, so the one ModelInstance call is declared here.
class ModelInstance {
public:
    void breakJoints();                          // 00584c00 (Instance::for_eachChild 0045c470 over 00584ba0)
private:
    ModelInstance();
};
class Assembly;
class Primitive {
public:
    Assembly* getAssembly() const;               // 005e7570 ?getAssembly@Primitive@RBX@@QBEPAVAssembly@2@XZ
private:
    Primitive();
};
extern char sHumanoid[];
class Humanoid : public DescribedCreatable<Humanoid, Instance, sHumanoid> {
public:
    Primitive* getTorsoPrimitive() const;        // 005d90a0
    static ModelInstance* getCharacterFromHumanoid(Humanoid* humanoid); // 005d7670
    static Reflection::SignalDesc<Humanoid, void(bool)> event_Seated;      // 0097a558
    static Reflection::SignalDesc<Humanoid, void(bool)> event_FallingDown; // 0097a2f4
    static Reflection::SignalDesc<Humanoid, void(bool)> event_Strafing;    // 0097a348
    static Reflection::SignalDesc<Humanoid, void(float)> event_Running;    // 0097a504
private:
    Humanoid();
};
}

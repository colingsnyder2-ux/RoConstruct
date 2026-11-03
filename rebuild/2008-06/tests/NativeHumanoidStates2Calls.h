#pragma once
// Proposed declaration-only overlay for RBX::Humanoid (no Humanoid members declared).
// tests/record_native_humanoid_states2.py copies this to out/humanoid-states2-overlay/humanoid/Humanoid.h
// until a native Humanoid header exists; it is not a shared header.
// Evidence: RTTI .?AVHumanoid@RBX@@ (vtable 0083d47c) lists
// DescribedCreatable<Humanoid,Instance,sHumanoid> (sHumanoid mangles 3PADA) with Instance at +0
// and Reflection::SignalSource at +0x14. 00667810/00667930 (Freefall), 00667c40/00667cd0
// (Jumping) and 00667e20/00667ec0 (GettingUp) pass humanoid ? humanoid+0x14 : 0 to
// SignalDescriptor::findSignalInstance 0056b620 on 0097a47c, 0097a5fc and 0097a630, then call
// boost::signal1<void,bool>::operator() 005e1f00 on the instance +0x10. The static initializers
// 007f68d0/007f68b0/007f68f0 construct those descriptors (SignalDesc ctor 005dad30) with the
// names "FreeFalling"/"Jumping"/"GettingUp" and argument name "active".
#include "v8tree/Instance.h"
#include "reflection/signal.h"
namespace RBX {
class PartInstance;
extern char sHumanoid[];
class Humanoid : public DescribedCreatable<Humanoid, Instance, sHumanoid> {
public:
    PartInstance* getHead() const;               // 005d8a10 ?getHead@Humanoid@RBX@@QBEPAVPartInstance@2@XZ
    PartInstance* getTorso() const;              // 005d8b10 ?getTorso@Humanoid@RBX@@QBEPAVPartInstance@2@XZ
    static Reflection::SignalDesc<Humanoid, void(bool)> event_FreeFalling; // 0097a47c
    static Reflection::SignalDesc<Humanoid, void(bool)> event_Jumping;     // 0097a5fc
    static Reflection::SignalDesc<Humanoid, void(bool)> event_GettingUp;   // 0097a630
private:
    Humanoid();
};
}

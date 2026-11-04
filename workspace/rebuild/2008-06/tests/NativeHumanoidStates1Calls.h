#pragma once
// Proposed declaration-only overlay for RBX::Humanoid (no Humanoid members declared).
// tests/record_native_humanoid_states1.py copies this to out/humanoid-states1-overlay/humanoid/Humanoid.h
// until a native Humanoid header exists; it is not a shared header.
// Evidence: RTTI .?AVHumanoid@RBX@@ (vtable 0083d47c) lists
// DescribedCreatable<Humanoid,Instance,sHumanoid> (sHumanoid mangles 3PADA) with Instance at +0
// and Reflection::SignalSource at +0x14; 00666980/00666b20/00666bc0 pass humanoid ? humanoid+0x14 : 0
// to SignalDescriptor::findSignalInstance on 0097a504 (Running) and 0097a58c (Climbing), then call
// boost::signal1<void,float>::operator() 004937f0 on the instance +0x10.
#include "v8tree/Instance.h"
#include "reflection/signal.h"
namespace RBX {
extern char sHumanoid[];
class Humanoid : public DescribedCreatable<Humanoid, Instance, sHumanoid> {
public:
    static Reflection::SignalDesc<Humanoid, void(float)> event_Running;   // 0097a504
    static Reflection::SignalDesc<Humanoid, void(float)> event_Climbing;  // 0097a58c
private:
    Humanoid();
};
}

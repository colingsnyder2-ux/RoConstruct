// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8tree/Instance.h"
#include "v8tree/InstanceEvents.h"

// INFERRED: 0056ab90 = signal empty() on the signal1 at SignalInstance+0x10; 006390a0 = signal1::operator()(event*, descriptor*)
extern "C" char __fastcall fn_0056ab90(void* signal, int unusedEdx);
extern "C" void __fastcall fn_006390a0(void* signal, int unusedEdx, void* event, const void* descriptor);

namespace RBX {

// INFERRED: PropertyChanged is only forward-declared in the headers; layout from the 8-byte stack local
// {descriptor, source} built at 0040db1d..0040db1f.
struct PropertyChanged {
    const Reflection::PropertyDescriptor* descriptor;
    const Reflection::SignalSource* source;
};

// findSignalInstance is protected; reach it through a derived class.
struct SignalFinder : Reflection::SignalDescriptor {
    static Reflection::SignalInstance* find(const Reflection::SignalDescriptor& d, const Reflection::SignalSource* s)
    {
        return (d.*(&SignalFinder::findSignalInstance))(s);
    }
};

// 0040db00
void Instance::raisePropertyChanged(const Reflection::PropertyDescriptor& descriptor)
{
    const Reflection::SignalSource* source =
        this ? reinterpret_cast<const Reflection::SignalSource*>(reinterpret_cast<const char*>(this) + 0x14) : 0;
    PropertyChanged event;
    event.descriptor = &descriptor;
    event.source = source;
    Notifier<Instance, PropertyChanged>::raise(event);

    Reflection::SignalInstance* signal = SignalFinder::find(event_itemChanged, source);
    if (signal && !fn_0056ab90(reinterpret_cast<char*>(signal) + 0x10, 0)) {
        signal = SignalFinder::find(event_itemChanged, source);
        if (signal)
            fn_006390a0(reinterpret_cast<char*>(signal) + 0x10, 0, &event, &descriptor);
    }

    // INFERRED: virtual slot 0x3c on the object at +0x104 is onChildChanged(Instance*, const PropertyChanged&)
    if (parent)
        parent->onChildChanged(this, event);
}
}

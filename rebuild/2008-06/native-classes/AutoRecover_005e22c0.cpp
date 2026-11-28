// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Lighting2008.h"

extern "C" char g_0097a900[];   // PropertyDescriptor for ColorShift_Top
// boost::signal1<void,bool,...>::operator() (0x005e1f00); first stack arg is the hidden return buffer.
extern "C" void __fastcall fn_005e1f00(void* signal, int unusedEdx, void* retBuf, bool arg);
extern "C" int fn_004651c0(int a1);

namespace RBX {

// INFERRED: minimal declaration of RunService (header not available).
class RunService
{
public:
    void invalidateRunViews();
};

namespace {
// INFERRED: access helper to reach the protected SignalDescriptor::findSignalInstance.
struct SignalDescAccess : public Reflection::SignalDescriptor
{
    typedef Reflection::SignalInstance* (Reflection::SignalDescriptor::*FindFn)(const Reflection::SignalSource*) const;
    static FindFn find() { return &SignalDescAccess::findSignalInstance; }
};
}

// INFERRED: the binary writes the ColorShift_Top group (+0x270), not ambientTop (+0x228).
void Lighting::setAmbientTop(G3D::Color3 value)
{
    if (colorShiftTop != value)
    {
        colorShiftTop = value;

        raisePropertyChanged(
            *reinterpret_cast<const Reflection::PropertyDescriptor*>(g_0097a900));

        // INFERRED: inlined fireLightingChanged(false)
        const Reflection::SignalSource* source = this;
        const Reflection::SignalDescriptor& desc = event_LightingChanged;
        Reflection::SignalInstance* inst = (desc.*SignalDescAccess::find())(source);
        if (inst)
        {
            char retBuf;
            fn_005e1f00((char*)inst + 0x10, 0, &retBuf, false);
        }

        RunService* runService = (RunService*)fn_004651c0((int)this);
        if (runService)
            runService->invalidateRunViews();
    }
}

}

// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "v8datamodel/ClickDetector.h"
#include "Network/Players.h"

// INFERRED: unknown globals (property descriptor desc_FrontendMouseClick and signal descriptor event_MouseClick)
extern "C" char g_0097bf64[];
extern "C" char g_0097bf80[];

extern "C" void __fastcall fn_00629ac0(RBX::ClickDetector* self, int unusedEdx, RBX::PartInstance* part, float distance)
{
    float& maxActivationDistance = *reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x144);
    bool& frontendMouseClick = *reinterpret_cast<bool*>(reinterpret_cast<char*>(self) + 0x148);
    if (distance < maxActivationDistance) {
        frontendMouseClick = !frontendMouseClick;
        self->raisePropertyChanged(
            *reinterpret_cast<const RBX::Reflection::PropertyDescriptor*>(g_0097bf64));
        if (RBX::Network::Players::backendProcessing(self, true)) {
            reinterpret_cast<RBX::Reflection::SignalDesc<RBX::ClickDetector, void(void)>*>(g_0097bf80)->fire(self);
        }
    }
}

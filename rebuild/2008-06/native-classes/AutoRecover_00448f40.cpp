// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "CRenderSettings.h"
#include "reflection/enumconverter.h"
#include <algorithm>

// INFERRED: field names are guesses. The 0x144/0x148 offsets come from the disassembly.
// The descriptor at 0x0096d448 is an unknown global, so it is declared as an extern.
extern "C" char g_0096d448[];

extern "C" void __fastcall fn_00448f40(CRenderSettings* self, int unusedEdx, float value)
{
    float* quality = (float*)((char*)self + 0x144);
    float* maxQuality = (float*)((char*)self + 0x148);

    if (value > *maxQuality)
        self->setMaxShadingQuality(value);

    float v = std::min(*maxQuality, value);
    v = std::max(0.0f, v);

    if (*quality != v) {
        *quality = v;
        ((RBX::Instance*)self)->raisePropertyChanged(
            *(RBX::Reflection::PropertyDescriptor*)g_0096d448);
    }
}

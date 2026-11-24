// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "CRenderSettings.h"
#include "v8tree/Instance.h"

// INFERRED: global property descriptor at 0x0096d464 (MaxShadingQuality); the type is abstract, so it is declared as raw storage and cast.
extern "C" char g_prop_0096d464[];
// INFERRED: float constant at 0x008163a4, upper clamp bound.
extern const float kShadingQualityUpper;

// INFERRED: unnamed setter; clamps value to [minShadingQuality, upper] and raises change.
extern "C" void __fastcall fn_00448fd0(CRenderSettings* self, int unusedEdx, float value)
{
    float* minQ = (float*)((char*)self + 0x144);
    float* maxQ = (float*)((char*)self + 0x148);

    if (value < *minQ)
        self->setMinShadingQuality(value);

    const float* p = (*minQ < value) ? &value : minQ;
    float v = *p;
    const float* q = (v < kShadingQualityUpper) ? &v : &kShadingQualityUpper;

    if (*maxQ != *q) {
        *maxQ = *q;
        ((RBX::Instance*)self)->raisePropertyChanged(*(RBX::Reflection::PropertyDescriptor*)g_prop_0096d464);
    }
}

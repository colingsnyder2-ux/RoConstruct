// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <algorithm>

// INFERRED: no class header was available; this is a minimal layout with only the two floats the function touches.
struct ClampedValueObject {
    char  pad[0x14c];
    float value;     // +0x14c
    float maxValue;  // +0x150
};

// INFERRED: 0x0040db00 is a property-changed notifier taking a descriptor pointer (0x96d480 here).
extern "C" void __fastcall fn_0040db00(void* self, int unusedEdx, const void* descriptor);

// INFERRED: a setter that clamps the new value to [0, maxValue] and notifies if it changed.
extern "C" void __fastcall fn_00449060(ClampedValueObject* self, int unusedEdx, float v)
{
    const float zero = 0.0f;
    float clamped = std::min(self->maxValue, std::max(zero, v));
    if (self->value != clamped) {
        self->value = clamped;
        fn_0040db00(self, 0, (const void*)0x96d480);
    }
}

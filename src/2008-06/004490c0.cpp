// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_renderclampbarrier_4e994b353a02fcf7.cpp

// Candidate translation unit (score above; library headers required).
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)
struct PropertyDescriptor {};
extern const PropertyDescriptor property;
extern const float upperBound;

struct CRenderSettings
{
    char padding[0x14c];
    float lowerBound;
    float value;

    void raisePropertyChanged(const PropertyDescriptor&);
    void setValue(float);
};

void CRenderSettings::setValue(float incoming)
{
    const float upper = upperBound;
    const float& lowerClamped = lowerBound < incoming ? incoming : lowerBound;
    const float& clamped = lowerClamped < upper ? lowerClamped : upper;

    _ReadWriteBarrier();
    float result = clamped;
    if (result != value) {
        value = result;
        raisePropertyChanged(property);
    }
}

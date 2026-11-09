// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_reservecompareorder_7c26614ce2043135.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise, off)
// from server: 93% by colin
const float increment=1.0f;
const float limit=4294967296.0f;

struct S {
    char padding[24];
    float loadFactor;
    unsigned int threshold;

    void reserve(unsigned int count);
    void rehash(unsigned int count);
};

void S::reserve(unsigned int count)
{
    if (count > threshold) {
        unsigned int capacity = ~0u;
        float required = count / loadFactor + increment;
        if (limit > required)
            capacity = static_cast<unsigned int>(required);
        rehash(capacity);
    }
}

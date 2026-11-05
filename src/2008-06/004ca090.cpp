// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_capacitycompareorder_63543eec4c68d0e6.cpp

// Candidate translation unit (score above; library headers required).
// from server: 91% by king_originala
struct S
{
    unsigned char padding0[8];
    unsigned int count;
    unsigned char padding1[12];
    float scale;
    unsigned int result;

    void update();
};

void S::update()
{
    float value = (float)count * scale;
    result = 0xffffffffU;
    if (4294967296.0f > value)
        result = (unsigned int)value;
}

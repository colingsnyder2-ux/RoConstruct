// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_vectorwriteinline_4632df7afb51dd3c.cpp

// Candidate translation unit (score above; library headers required).
// from server: 97% by king_originala
extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)
#pragma float_control(precise, off)

struct S {
    void writeBits(const unsigned char *, int, bool);
    void writeComponent(float);
    __forceinline void write(float data) {writeBits((const unsigned char*)&data,32,true);}
    void f(float, float, float);
};

void S::f(float x, float y, float z)
{
    float length = (float)sqrt(x * x + y * y + z * z);
    write(length);

    if (length > 0.0f) {
        writeComponent(x / length);
        writeComponent(y / length);
        writeComponent(z / length);
    }
}

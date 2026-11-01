// from server: 100% by Espeon
#include <intrin.h>

extern "C" double __cdecl fabs(double);
#pragma intrinsic(fabs)

struct S {
    void Write0();
    void Write1();
    void WriteBits(const unsigned char*, int, bool);
    void Write(unsigned short value) {WriteBits((const unsigned char*)&value,16,true);}
    void WriteNormQuat(float w, float x, float y, float z);
};

void S::WriteNormQuat(float w, float x, float y, float z)
{
    if (w < 0.0f)
        Write1();
    else
        Write0();

    if (x < 0.0f)
        Write1();
    else
        Write0();

    if (y < 0.0f)
        Write1();
    else
        Write0();

    if (z < 0.0f)
        Write1();
    else
        Write0();

    Write((unsigned short)(fabs(x)*65535.0));
    Write((unsigned short)(fabs(y)*65535.0));
    Write((unsigned short)(fabs(z)*65535.0));
}

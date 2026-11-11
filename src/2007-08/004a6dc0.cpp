// from server: 100% by EspClaude
// from server: 81% by tajop
// roc 2007-08 004a6dc0  unit: RBX::Network::Replicator  size: 193 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a6dc0
//
// 004a6dc0  83ec08               sub esp, 8
// 004a6dc3  d944240c             fld dword ptr [esp + 0xc]
// 004a6dc7  56                   push esi
// 004a6dc8  d9442414             fld dword ptr [esp + 0x14]
// 004a6dcc  8bf1                 mov esi, ecx
// 004a6dce  d9442418             fld dword ptr [esp + 0x18]
// 004a6dd2  d9c1                 fld st(1)
// 004a6dd4  deca                 fmulp st(2)
// 004a6dd6  d9c2                 fld st(2)
// 004a6dd8  decb                 fmulp st(3)
// 004a6dda  d9c9                 fxch st(1)
// 004a6ddc  dec2                 faddp st(2)
// 004a6dde  dcc8                 fmul st(0), st(0)
// 004a6de0  dec1                 faddp st(1)
// 004a6de2  d95c2404             fstp dword ptr [esp + 4]
// 004a6de6  d9442404             fld dword ptr [esp + 4]
// 004a6dea  e81da01800           call 0x630e0c
// 004a6def  d95c2404             fstp dword ptr [esp + 4]
// 004a6df3  d9442404             fld dword ptr [esp + 4]
// 004a6df7  6a01                 push 1
// 004a6df9  d95c2408             fstp dword ptr [esp + 8]
// 004a6dfd  6a20                 push 0x20
// 004a6dff  d944240c             fld dword ptr [esp + 0xc]
// 004a6e03  8d442410             lea eax, [esp + 0x10]
// 004a6e07  50                   push eax
// 004a6e08  d95c2414             fstp dword ptr [esp + 0x14]
// 004a6e0c  8bce                 mov ecx, esi
// 004a6e0e  e87d8fffff           call 0x49fd90
// 004a6e13  d9ee                 fldz 
// 004a6e15  d9442404             fld dword ptr [esp + 4]
// 004a6e19  d8d1                 fcom st(1)
// 004a6e1b  dfe0                 fnstsw ax
// 004a6e1d  ddd9                 fstp st(1)
// 004a6e1f  f6c441               test ah, 0x41
// 004a6e22  7554                 jne 0x4a6e78
// 004a6e24  d87c2410             fdivr dword ptr [esp + 0x10]
// 004a6e28  51                   push ecx
// 004a6e29  8bce                 mov ecx, esi
// 004a6e2b  d95c2414             fstp dword ptr [esp + 0x14]
// 004a6e2f  d9442414             fld dword ptr [esp + 0x14]
// 004a6e33  d91c24               fstp dword ptr [esp]
// 004a6e36  e8a5f0ffff           call 0x4a5ee0
// 004a6e3b  d9442414             fld dword ptr [esp + 0x14]
// 004a6e3f  d8742404             fdiv dword ptr [esp + 4]
// 004a6e43  51                   push ecx
// 004a6e44  8bce                 mov ecx, esi
// 004a6e46  d95c2414             fstp dword ptr [esp + 0x14]
// 004a6e4a  d9442414             fld dword ptr [esp + 0x14]
// 004a6e4e  d91c24               fstp dword ptr [esp]
// 004a6e51  e88af0ffff           call 0x4a5ee0
// 004a6e56  d9442418             fld dword ptr [esp + 0x18]
// 004a6e5a  d8742404             fdiv dword ptr [esp + 4]
// 004a6e5e  51                   push ecx
// 004a6e5f  8bce                 mov ecx, esi
// 004a6e61  d95c2414             fstp dword ptr [esp + 0x14]
// 004a6e65  d9442414             fld dword ptr [esp + 0x14]
// 004a6e69  d91c24               fstp dword ptr [esp]
// 004a6e6c  e86ff0ffff           call 0x4a5ee0
// 004a6e71  5e                   pop esi
// 004a6e72  83c408               add esp, 8
// 004a6e75  c20c00               ret 0xc
// 004a6e78  ddd8                 fstp st(0)
// 004a6e7a  5e                   pop esi
// 004a6e7b  83c408               add esp, 8
// 004a6e7e  c20c00               ret 0xc

#include <math.h>

struct BitStream
{
    void WriteBits(const unsigned char* input, int numberOfBitsToWrite, bool rightAlignedBits);
    void WriteCompressed(float var);
    inline void Write(float var)
    {
        WriteBits((unsigned char*)&var, sizeof(var) * 8, true);
    }
    void WriteVector(float x, float y, float z);
};

void BitStream::WriteVector(float x, float y, float z)
{
    float magnitude = sqrt(x * x + y * y + z * z);
    Write(magnitude);
    if (magnitude > 0.0f)
    {
        WriteCompressed((float)(x / magnitude));
        WriteCompressed((float)(y / magnitude));
        WriteCompressed((float)(z / magnitude));
    }
}

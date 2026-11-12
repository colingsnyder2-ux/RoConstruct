// from server: 90% by EspClaude
// from server: 42% by colin
// roc 2007-08 004a6c90  unit: RBX::Network::Replicator  size: 291 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a6c90
//
// 004a6c90  83ec10               sub esp, 0x10
// 004a6c93  56                   push esi
// 004a6c94  6a01                 push 1
// 004a6c96  6a20                 push 0x20
// 004a6c98  8d442410             lea eax, [esp + 0x10]
// 004a6c9c  50                   push eax
// 004a6c9d  8bf1                 mov esi, ecx
// 004a6c9f  e8fc8cffff           call 0x49f9a0
// 004a6ca4  84c0                 test al, al
// 004a6ca6  7509                 jne 0x4a6cb1
// 004a6ca8  32c0                 xor al, al
// 004a6caa  5e                   pop esi
// 004a6cab  83c410               add esp, 0x10
// 004a6cae  c20c00               ret 0xc
// 004a6cb1  d9ee                 fldz 
// 004a6cb3  d8542408             fcom dword ptr [esp + 8]
// 004a6cb7  dfe0                 fnstsw ax
// 004a6cb9  f6c444               test ah, 0x44
// 004a6cbc  0f8bd6000000         jnp 0x4a6d98
// 004a6cc2  6a01                 push 1
// 004a6cc4  ddd8                 fstp st(0)
// 004a6cc6  6a10                 push 0x10
// 004a6cc8  8d4c240c             lea ecx, [esp + 0xc]
// 004a6ccc  51                   push ecx
// 004a6ccd  8bce                 mov ecx, esi
// 004a6ccf  e8cc8cffff           call 0x49f9a0
// 004a6cd4  84c0                 test al, al
// 004a6cd6  741d                 je 0x4a6cf5
// 004a6cd8  0fb7542404           movzx edx, word ptr [esp + 4]
// 004a6cdd  89542404             mov dword ptr [esp + 4], edx
// 004a6ce1  db442404             fild dword ptr [esp + 4]
// 004a6ce5  dc3520d47900         fdiv qword ptr [0x79d420]
// 004a6ceb  dc2598317900         fsub qword ptr [0x793198]
// 004a6cf1  d95c240c             fstp dword ptr [esp + 0xc]
// 004a6cf5  6a01                 push 1
// 004a6cf7  6a10                 push 0x10
// 004a6cf9  8d44240c             lea eax, [esp + 0xc]
// 004a6cfd  50                   push eax
// 004a6cfe  8bce                 mov ecx, esi
// 004a6d00  e89b8cffff           call 0x49f9a0
// 004a6d05  84c0                 test al, al
// 004a6d07  741d                 je 0x4a6d26
// 004a6d09  0fb74c2404           movzx ecx, word ptr [esp + 4]
// 004a6d0e  894c2404             mov dword ptr [esp + 4], ecx
// 004a6d12  db442404             fild dword ptr [esp + 4]
// 004a6d16  dc3520d47900         fdiv qword ptr [0x79d420]
// 004a6d1c  dc2598317900         fsub qword ptr [0x793198]
// 004a6d22  d95c2410             fstp dword ptr [esp + 0x10]
// 004a6d26  6a01                 push 1
// 004a6d28  6a10                 push 0x10
// 004a6d2a  8d54240c             lea edx, [esp + 0xc]
// 004a6d2e  52                   push edx
// 004a6d2f  8bce                 mov ecx, esi
// 004a6d31  e86a8cffff           call 0x49f9a0
// 004a6d36  84c0                 test al, al
// 004a6d38  0f846affffff         je 0x4a6ca8
// 004a6d3e  0fb7442404           movzx eax, word ptr [esp + 4]
// 004a6d43  89442404             mov dword ptr [esp + 4], eax
// 004a6d47  8b442418             mov eax, dword ptr [esp + 0x18]
// 004a6d4b  db442404             fild dword ptr [esp + 4]
// 004a6d4f  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004a6d53  8b542420             mov edx, dword ptr [esp + 0x20]
// 004a6d57  5e                   pop esi
// 004a6d58  dc3520d47900         fdiv qword ptr [0x79d420]
// 004a6d5e  dc2598317900         fsub qword ptr [0x793198]
// 004a6d64  d91c24               fstp dword ptr [esp]
// 004a6d67  d9442408             fld dword ptr [esp + 8]
// 004a6d6b  d918                 fstp dword ptr [eax]
// 004a6d6d  d944240c             fld dword ptr [esp + 0xc]
// 004a6d71  d919                 fstp dword ptr [ecx]
// 004a6d73  d90424               fld dword ptr [esp]
// 004a6d76  d91a                 fstp dword ptr [edx]
// 004a6d78  d900                 fld dword ptr [eax]
// 004a6d7a  d9442404             fld dword ptr [esp + 4]
// 004a6d7e  d9c0                 fld st(0)
// 004a6d80  deca                 fmulp st(2)
// 004a6d82  d9c9                 fxch st(1)
// 004a6d84  d918                 fstp dword ptr [eax]
// 004a6d86  b001                 mov al, 1
// 004a6d88  d901                 fld dword ptr [ecx]
// 004a6d8a  d8c9                 fmul st(1)
// 004a6d8c  d919                 fstp dword ptr [ecx]
// 004a6d8e  d80a                 fmul dword ptr [edx]
// 004a6d90  d91a                 fstp dword ptr [edx]
// 004a6d92  83c410               add esp, 0x10
// 004a6d95  c20c00               ret 0xc
// 004a6d98  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004a6d9c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004a6da0  d911                 fst dword ptr [ecx]
// 004a6da2  8b442420             mov eax, dword ptr [esp + 0x20]
// 004a6da6  d912                 fst dword ptr [edx]
// 004a6da8  d918                 fstp dword ptr [eax]
// 004a6daa  b001                 mov al, 1

// RakNet BitStream::ReadVector<float> with ReadNormVector inlined.
// ReadBits(this, ptr, bits, alignRight=1) at 0x49f9a0; 0x79d420 / 0x793198 are double constants.
extern "C" {
extern double G_double_0079d420;
extern double G_double_00793198;
}

class BitStream {
public:
    bool ReadBits(unsigned char* output, int numberOfBitsToRead, bool alignBitsToRight);

    template <class T> __forceinline bool Read(T& var) {
        return ReadBits((unsigned char*)&var, sizeof(T) * 8, true);
    }

    template <class T> __forceinline bool ReadNormVector(T& x, T& y, T& z) {
        unsigned short s;
        float cx, cy, cz;
        if (Read(s)) cx = (float)(s / G_double_0079d420 - G_double_00793198);
        if (Read(s)) cy = (float)(s / G_double_0079d420 - G_double_00793198);
        if (!Read(s)) return false;
        cz = (float)(s / G_double_0079d420 - G_double_00793198);
        x = cx; y = cy; z = cz;
        return true;
    }

    bool ReadVector(float& x, float& y, float& z);
};

bool BitStream::ReadVector(float& x, float& y, float& z)
{
    float magnitude;
    if (!Read(magnitude))
        return false;
    if (magnitude != 0.0) {
        if (!ReadNormVector(x, y, z))
            return false;
        x *= magnitude;
        y *= magnitude;
        z *= magnitude;
    } else {
        x = 0.0;
        y = 0.0;
        z = 0.0;
    }
    return true;
}

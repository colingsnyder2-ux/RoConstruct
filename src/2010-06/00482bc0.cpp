// from server: 100% by Yeetserama
// roc 2010-06 00482bc0  unit: RBX::LDraw2Lua::LDrawCommand  size: 546 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00482bc0
//
// 00482bc0  6aff                 push -1
// 00482bc2  68a97e9900           push 0x997ea9
// 00482bc7  64a100000000         mov eax, dword ptr fs:[0]
// 00482bcd  50                   push eax
// 00482bce  64892500000000       mov dword ptr fs:[0], esp
// 00482bd5  83ec20               sub esp, 0x20
// 00482bd8  56                   push esi
// 00482bd9  8bf1                 mov esi, ecx
// 00482bdb  8d4c2438             lea ecx, [esp + 0x38]
// 00482bdf  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00482be7  ff1508a49e00         call dword ptr [0x9ea408]
// 00482bed  50                   push eax
// 00482bee  ff1548a79e00         call dword ptr [0x9ea748]
// 00482bf4  dd4610               fld qword ptr [esi + 0x10]
// 00482bf7  dc0dd030a100         fmul qword ptr [0xa130d0]
// 00482bfd  83c404               add esp, 4
// 00482c00  dd4618               fld qword ptr [esi + 0x18]
// 00482c03  68fc6ea000           push 0xa06efc
// 00482c08  dd05c830a100         fld qword ptr [0xa130c8]
// 00482c0e  83ec08               sub esp, 8
// 00482c11  dcc9                 fmul st(1), st(0)
// 00482c13  d9c9                 fxch st(1)
// 00482c15  dee3                 fsubrp st(3)
// 00482c17  dc4e20               fmul qword ptr [esi + 0x20]
// 00482c1a  dd4628               fld qword ptr [esi + 0x28]
// 00482c1d  dd4630               fld qword ptr [esi + 0x30]
// 00482c20  dd4638               fld qword ptr [esi + 0x38]
// 00482c23  dd4640               fld qword ptr [esi + 0x40]
// 00482c26  dd4648               fld qword ptr [esi + 0x48]
// 00482c29  dd5c2428             fstp qword ptr [esp + 0x28]
// 00482c2d  dd4650               fld qword ptr [esi + 0x50]
// 00482c30  dd5c2420             fstp qword ptr [esp + 0x20]
// 00482c34  dd4658               fld qword ptr [esi + 0x58]
// 00482c37  dd5c2418             fstp qword ptr [esp + 0x18]
// 00482c3b  dd4660               fld qword ptr [esi + 0x60]
// 00482c3e  dd5c2410             fstp qword ptr [esp + 0x10]
// 00482c42  dd4668               fld qword ptr [esi + 0x68]
// 00482c45  8b742440             mov esi, dword ptr [esp + 0x40]
// 00482c49  dd1c24               fstp qword ptr [esp]
// 00482c4c  68c430a100           push 0xa130c4
// 00482c51  dd442414             fld qword ptr [esp + 0x14]
// 00482c55  83ec08               sub esp, 8
// 00482c58  dd1c24               fstp qword ptr [esp]
// 00482c5b  68c430a100           push 0xa130c4
// 00482c60  dd442428             fld qword ptr [esp + 0x28]
// 00482c64  83ec08               sub esp, 8
// 00482c67  dd1c24               fstp qword ptr [esp]
// 00482c6a  68c430a100           push 0xa130c4
// 00482c6f  dd44243c             fld qword ptr [esp + 0x3c]
// 00482c73  83ec08               sub esp, 8
// 00482c76  dd1c24               fstp qword ptr [esp]
// 00482c79  68c430a100           push 0xa130c4
// 00482c7e  dd442450             fld qword ptr [esp + 0x50]
// 00482c82  83ec08               sub esp, 8
// 00482c85  dd1c24               fstp qword ptr [esp]
// 00482c88  68c430a100           push 0xa130c4
// 00482c8d  83ec08               sub esp, 8
// 00482c90  dd1c24               fstp qword ptr [esp]
// 00482c93  68c430a100           push 0xa130c4
// 00482c98  83ec08               sub esp, 8
// 00482c9b  dd1c24               fstp qword ptr [esp]
// 00482c9e  68c430a100           push 0xa130c4
// 00482ca3  83ec08               sub esp, 8
// 00482ca6  dd1c24               fstp qword ptr [esp]
// 00482ca9  68c430a100           push 0xa130c4
// 00482cae  83ec08               sub esp, 8
// 00482cb1  dd1c24               fstp qword ptr [esp]
// 00482cb4  68c430a100           push 0xa130c4
// 00482cb9  83ec08               sub esp, 8
// 00482cbc  dd1c24               fstp qword ptr [esp]
// 00482cbf  68c430a100           push 0xa130c4
// 00482cc4  83ec08               sub esp, 8
// 00482cc7  d9c9                 fxch st(1)
// 00482cc9  dd1c24               fstp qword ptr [esp]
// 00482ccc  68c430a100           push 0xa130c4
// 00482cd1  83ec08               sub esp, 8
// 00482cd4  dd1c24               fstp qword ptr [esp]
// 00482cd7  68a830a100           push 0xa130a8
// 00482cdc  56                   push esi
// 00482cdd  e83eb2fcff           call 0x44df20
// 00482ce2  83c408               add esp, 8
// 00482ce5  8bc8                 mov ecx, eax
// 00482ce7  ff154ca59e00         call dword ptr [0x9ea54c]
// 00482ced  50                   push eax
// 00482cee  e82db2fcff           call 0x44df20
// 00482cf3  83c408               add esp, 8
// 00482cf6  8bc8                 mov ecx, eax
// 00482cf8  ff154ca59e00         call dword ptr [0x9ea54c]
// 00482cfe  50                   push eax
// 00482cff  e81cb2fcff           call 0x44df20
// 00482d04  83c408               add esp, 8
// 00482d07  8bc8                 mov ecx, eax
// 00482d09  ff154ca59e00         call dword ptr [0x9ea54c]
// 00482d0f  50                   push eax
// 00482d10  e80bb2fcff           call 0x44df20
// 00482d15  83c408               add esp, 8
// 00482d18  8bc8                 mov ecx, eax
// 00482d1a  ff154ca59e00         call dword ptr [0x9ea54c]
// 00482d20  50                   push eax
// 00482d21  e8fab1fcff           call 0x44df20
// 00482d26  83c408               add esp, 8
// 00482d29  8bc8                 mov ecx, eax
// 00482d2b  ff154ca59e00         call dword ptr [0x9ea54c]
// 00482d31  50                   push eax
// 00482d32  e8e9b1fcff           call 0x44df20
// 00482d37  83c408               add esp, 8
// 00482d3a  8bc8                 mov ecx, eax
// 00482d3c  ff154ca59e00         call dword ptr [0x9ea54c]
// 00482d42  50                   push eax
// 00482d43  e8d8b1fcff           call 0x44df20
// 00482d48  83c408               add esp, 8
// 00482d4b  8bc8                 mov ecx, eax
// 00482d4d  ff154ca59e00         call dword ptr [0x9ea54c]
// 00482d53  50                   push eax
// 00482d54  e8c7b1fcff           call 0x44df20
// 00482d59  83c408               add esp, 8
// 00482d5c  8bc8                 mov ecx, eax
// 00482d5e  ff154ca59e00         call dword ptr [0x9ea54c]
// 00482d64  50                   push eax
// 00482d65  e8b6b1fcff           call 0x44df20
// 00482d6a  83c408               add esp, 8
// 00482d6d  8bc8                 mov ecx, eax
// 00482d6f  ff154ca59e00         call dword ptr [0x9ea54c]
// 00482d75  50                   push eax
// 00482d76  e8a5b1fcff           call 0x44df20
// 00482d7b  83c408               add esp, 8
// 00482d7e  8bc8                 mov ecx, eax
// 00482d80  ff154ca59e00         call dword ptr [0x9ea54c]
// 00482d86  50                   push eax
// 00482d87  e894b1fcff           call 0x44df20
// 00482d8c  83c408               add esp, 8
// 00482d8f  8bc8                 mov ecx, eax
// 00482d91  ff154ca59e00         call dword ptr [0x9ea54c]
// 00482d97  50                   push eax
// 00482d98  e883b1fcff           call 0x44df20
// 00482d9d  83c408               add esp, 8
// 00482da0  8bc8                 mov ecx, eax
// 00482da2  ff154ca59e00         call dword ptr [0x9ea54c]
// 00482da8  50                   push eax
// 00482da9  e872b1fcff           call 0x44df20
// 00482dae  686431a100           push 0xa13164
// 00482db3  56                   push esi
// 00482db4  e867b1fcff           call 0x44df20
// 00482db9  83c410               add esp, 0x10
// 00482dbc  8d4c2438             lea ecx, [esp + 0x38]
// 00482dc0  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 00482dc8  ff1500a49e00         call dword ptr [0x9ea400]
// 00482dce  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00482dd2  32c0                 xor al, al
// 00482dd4  5e                   pop esi
// 00482dd5  64890d00000000       mov dword ptr fs:[0], ecx
// 00482ddc  83c42c               add esp, 0x2c
// 00482ddf  c22000               ret 0x20
// copied from an identical function in another client (function ?writeCFrame@LDrawCommand@@QAE_NAAV?$basic_ostream@DU?$char_traits@D@std@@@std@@UText@@@Z)

// from server: 66% by colin
// roc 2008-06 0046ed40  unit: RBX::LDraw2Lua::LDrawCommand  size: 546 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046ed40
//
// 0046ed40  6aff                 push -1
// 0046ed42  68793f7c00           push 0x7c3f79
// 0046ed47  64a100000000         mov eax, dword ptr fs:[0]
// 0046ed4d  50                   push eax
// 0046ed4e  64892500000000       mov dword ptr fs:[0], esp
// 0046ed55  83ec20               sub esp, 0x20
// 0046ed58  56                   push esi
// 0046ed59  8bf1                 mov esi, ecx
// 0046ed5b  8d4c2438             lea ecx, [esp + 0x38]
// 0046ed5f  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0046ed67  ff1564248000         call dword ptr [0x802464]
// 0046ed6d  50                   push eax
// 0046ed6e  ff15fc278000         call dword ptr [0x8027fc]
// 0046ed74  dd4610               fld qword ptr [esi + 0x10]
// 0046ed77  dc0d38cb8100         fmul qword ptr [0x81cb38]
// 0046ed7d  83c404               add esp, 4
// 0046ed80  dd4618               fld qword ptr [esi + 0x18]
// 0046ed83  685c2e8100           push 0x812e5c
// 0046ed88  dd0530cb8100         fld qword ptr [0x81cb30]
// 0046ed8e  83ec08               sub esp, 8
// 0046ed91  dcc9                 fmul st(1), st(0)
// 0046ed93  d9c9                 fxch st(1)
// 0046ed95  dee3                 fsubrp st(3)
// 0046ed97  dc4e20               fmul qword ptr [esi + 0x20]
// 0046ed9a  dd4628               fld qword ptr [esi + 0x28]
// 0046ed9d  dd4630               fld qword ptr [esi + 0x30]
// 0046eda0  dd4638               fld qword ptr [esi + 0x38]
// 0046eda3  dd4640               fld qword ptr [esi + 0x40]
// 0046eda6  dd4648               fld qword ptr [esi + 0x48]
// 0046eda9  dd5c2428             fstp qword ptr [esp + 0x28]
// 0046edad  dd4650               fld qword ptr [esi + 0x50]
// 0046edb0  dd5c2420             fstp qword ptr [esp + 0x20]
// 0046edb4  dd4658               fld qword ptr [esi + 0x58]
// 0046edb7  dd5c2418             fstp qword ptr [esp + 0x18]
// 0046edbb  dd4660               fld qword ptr [esi + 0x60]
// 0046edbe  dd5c2410             fstp qword ptr [esp + 0x10]
// 0046edc2  dd4668               fld qword ptr [esi + 0x68]
// 0046edc5  8b742440             mov esi, dword ptr [esp + 0x40]
// 0046edc9  dd1c24               fstp qword ptr [esp]
// 0046edcc  6828cb8100           push 0x81cb28
// 0046edd1  dd442414             fld qword ptr [esp + 0x14]
// 0046edd5  83ec08               sub esp, 8
// 0046edd8  dd1c24               fstp qword ptr [esp]
// 0046eddb  6828cb8100           push 0x81cb28
// 0046ede0  dd442428             fld qword ptr [esp + 0x28]
// 0046ede4  83ec08               sub esp, 8
// 0046ede7  dd1c24               fstp qword ptr [esp]
// 0046edea  6828cb8100           push 0x81cb28
// 0046edef  dd44243c             fld qword ptr [esp + 0x3c]
// 0046edf3  83ec08               sub esp, 8
// 0046edf6  dd1c24               fstp qword ptr [esp]
// 0046edf9  6828cb8100           push 0x81cb28
// 0046edfe  dd442450             fld qword ptr [esp + 0x50]
// 0046ee02  83ec08               sub esp, 8
// 0046ee05  dd1c24               fstp qword ptr [esp]
// 0046ee08  6828cb8100           push 0x81cb28
// 0046ee0d  83ec08               sub esp, 8
// 0046ee10  dd1c24               fstp qword ptr [esp]
// 0046ee13  6828cb8100           push 0x81cb28
// 0046ee18  83ec08               sub esp, 8
// 0046ee1b  dd1c24               fstp qword ptr [esp]
// 0046ee1e  6828cb8100           push 0x81cb28
// 0046ee23  83ec08               sub esp, 8
// 0046ee26  dd1c24               fstp qword ptr [esp]
// 0046ee29  6828cb8100           push 0x81cb28
// 0046ee2e  83ec08               sub esp, 8
// 0046ee31  dd1c24               fstp qword ptr [esp]
// 0046ee34  6828cb8100           push 0x81cb28
// 0046ee39  83ec08               sub esp, 8
// 0046ee3c  dd1c24               fstp qword ptr [esp]
// 0046ee3f  6828cb8100           push 0x81cb28
// 0046ee44  83ec08               sub esp, 8
// 0046ee47  d9c9                 fxch st(1)
// 0046ee49  dd1c24               fstp qword ptr [esp]
// 0046ee4c  6828cb8100           push 0x81cb28
// 0046ee51  83ec08               sub esp, 8
// 0046ee54  dd1c24               fstp qword ptr [esp]
// 0046ee57  680ccb8100           push 0x81cb0c
// 0046ee5c  56                   push esi
// 0046ee5d  e8eeb5fdff           call 0x44a450
// 0046ee62  83c408               add esp, 8
// 0046ee65  8bc8                 mov ecx, eax
// 0046ee67  ff1578248000         call dword ptr [0x802478]
// 0046ee6d  50                   push eax
// 0046ee6e  e8ddb5fdff           call 0x44a450
// 0046ee73  83c408               add esp, 8
// 0046ee76  8bc8                 mov ecx, eax
// 0046ee78  ff1578248000         call dword ptr [0x802478]
// 0046ee7e  50                   push eax
// 0046ee7f  e8ccb5fdff           call 0x44a450
// 0046ee84  83c408               add esp, 8
// 0046ee87  8bc8                 mov ecx, eax
// 0046ee89  ff1578248000         call dword ptr [0x802478]
// 0046ee8f  50                   push eax
// 0046ee90  e8bbb5fdff           call 0x44a450
// 0046ee95  83c408               add esp, 8
// 0046ee98  8bc8                 mov ecx, eax
// 0046ee9a  ff1578248000         call dword ptr [0x802478]
// 0046eea0  50                   push eax
// 0046eea1  e8aab5fdff           call 0x44a450
// 0046eea6  83c408               add esp, 8
// 0046eea9  8bc8                 mov ecx, eax
// 0046eeab  ff1578248000         call dword ptr [0x802478]
// 0046eeb1  50                   push eax
// 0046eeb2  e899b5fdff           call 0x44a450
// 0046eeb7  83c408               add esp, 8
// 0046eeba  8bc8                 mov ecx, eax
// 0046eebc  ff1578248000         call dword ptr [0x802478]
// 0046eec2  50                   push eax
// 0046eec3  e888b5fdff           call 0x44a450
// 0046eec8  83c408               add esp, 8
// 0046eecb  8bc8                 mov ecx, eax
// 0046eecd  ff1578248000         call dword ptr [0x802478]
// 0046eed3  50                   push eax
// 0046eed4  e877b5fdff           call 0x44a450
// 0046eed9  83c408               add esp, 8
// 0046eedc  8bc8                 mov ecx, eax
// 0046eede  ff1578248000         call dword ptr [0x802478]
// 0046eee4  50                   push eax
// 0046eee5  e866b5fdff           call 0x44a450
// 0046eeea  83c408               add esp, 8
// 0046eeed  8bc8                 mov ecx, eax
// 0046eeef  ff1578248000         call dword ptr [0x802478]
// 0046eef5  50                   push eax
// 0046eef6  e855b5fdff           call 0x44a450
// 0046eefb  83c408               add esp, 8
// 0046eefe  8bc8                 mov ecx, eax
// 0046ef00  ff1578248000         call dword ptr [0x802478]
// 0046ef06  50                   push eax
// 0046ef07  e844b5fdff           call 0x44a450
// 0046ef0c  83c408               add esp, 8
// 0046ef0f  8bc8                 mov ecx, eax
// 0046ef11  ff1578248000         call dword ptr [0x802478]
// 0046ef17  50                   push eax
// 0046ef18  e833b5fdff           call 0x44a450
// 0046ef1d  83c408               add esp, 8
// 0046ef20  8bc8                 mov ecx, eax
// 0046ef22  ff1578248000         call dword ptr [0x802478]
// 0046ef28  50                   push eax
// 0046ef29  e822b5fdff           call 0x44a450
// 0046ef2e  68cccb8100           push 0x81cbcc
// 0046ef33  56                   push esi
// 0046ef34  e817b5fdff           call 0x44a450
// 0046ef39  83c410               add esp, 0x10
// 0046ef3c  8d4c2438             lea ecx, [esp + 0x38]
// 0046ef40  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0046ef48  ff1568248000         call dword ptr [0x802468]
// 0046ef4e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0046ef52  32c0                 xor al, al
// 0046ef54  5e                   pop esi
// 0046ef55  64890d00000000       mov dword ptr fs:[0], ecx
// 0046ef5c  83c42c               add esp, 0x2c
// 0046ef5f  c22000               ret 0x20
#include <intrin.h>

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD

#include <cstdlib>
#include <ostream>

struct Text
{
    char storage[28];
    __declspec(dllimport) const char* c_str() const;
    __declspec(dllimport) ~Text();
};

struct LDrawCommand
{
    int command;
    int color;
    int line;
    int reserved;
    double x;
    double y;
    double z;
    double r00;
    double r01;
    double r02;
    double r10;
    double r11;
    double r12;
    double r20;
    double r21;
    double r22;

    bool writeCFrame(std::ostream& stream, Text offset);
};

bool LDrawCommand::writeCFrame(std::ostream& stream, Text offset)
{
    double value = atof(offset.c_str());
    double px = x * 0.05;
    double py = y * -0.05 - value;
    double pz = z * -0.05;
    double mr00 = r00;
    double mr01 = r01;
    double mr02 = r02;
    double mr10 = r10;
    double mr11 = r11;
    double mr12 = r12;
    double mr20 = r20;
    double mr21 = r21;
    double mr22 = r22;
    stream << "part.CFrame = CFrame.new("
        << px << "," << py << "," << pz << ","
        << mr00 << "," << mr01 << "," << mr02 << "," << mr10 << "," << mr11 << ","
        << mr12 << "," << mr20 << "," << mr21 << "," << mr22 << ")";
    stream << "\n";
    return false;
}
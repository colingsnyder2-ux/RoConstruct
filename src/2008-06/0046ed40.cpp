// from server: 100% by EspClaude
// from server: 67% by colin
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

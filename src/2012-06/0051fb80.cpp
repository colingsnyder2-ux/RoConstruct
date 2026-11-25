// from server: 100% by Xemicl
// from server: 100% by intel
// roc 2012-06 00769480  unit: std::D::DU?$char_traits::$$A6A_NV?$basic_string::?$CallbackDescImpl  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00769480
//
// 00769480  803db380e50000       cmp byte ptr [0xe580b3], 0
// 00769487  7442                 je 0x7694cb
// 00769489  813de079e3009a020000 cmp dword ptr [0xe379e0], 0x29a
// 00769493  7436                 je 0x7694cb
// 00769495  a19c80e500           mov eax, dword ptr [0xe5809c]
// 0076949a  85c0                 test eax, eax
// 0076949c  7418                 je 0x7694b6
// 0076949e  68cf000000           push 0xcf
// 007694a3  68a82fb400           push 0xb42fa8
// 007694a8  68902fb400           push 0xb42f90
// 007694ad  ffd0                 call eax
// 007694af  83c40c               add esp, 0xc
// 007694b2  84c0                 test al, al
// 007694b4  7515                 jne 0x7694cb
// 007694b6  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 007694bd  68202fb400           push 0xb42f20
// 007694c2  50                   push eax
// 007694c3  e8c88d2000           call 0x972290
// 007694c8  83c408               add esp, 8
// 007694cb  833dc40bbc0000       cmp dword ptr [0xbc0bc4], 0
// 007694d2  7505                 jne 0x7694d9
// 007694d4  e9a75ff1ff           jmp 0x67f480
// 007694d9  68a0817600           push 0x7681a0
// 007694de  68887ae300           push 0xe37a88
// 007694e3  e8b880c9ff           call 0x4015a0
// 007694e8  83c408               add esp, 8
// 007694eb  e920e9ffff           jmp 0x767e10

extern "C" int __cdecl sub_00972290(int, const char*);
extern "C" void __cdecl sub_004015a0(const char*, const char*);
extern "C" void __cdecl sub_0067f480();
extern "C" void __cdecl sub_00767160();

extern char g_e580b3;
extern int g_e3796c;
extern int g_e5809c;
extern int g_be7a7c;
extern char g_b42f20[];
extern char g_b42f90[];
extern char g_b42fa8[];
extern char g_e37a14[];
extern char g_767fd0[];

void func_007687d0()
{
    if (g_e580b3 != 0)
    {
        if (g_e3796c == 0x29a)
            goto L_76881b;
        if (g_e5809c != 0)
        {
            if (((char (__cdecl*)(int, char*, char*))g_e5809c)(0xcf, g_b42fa8, g_b42f90) != 0)
                goto L_76881b;
        }
        sub_00972290((unsigned char)g_e580b3, g_b42f20);
    }
L_76881b:
    if (g_be7a7c == 0)
    {
        sub_0067f480();
        return;
    }
    sub_004015a0(g_767fd0, g_e37a14);
    sub_00767160();
}

// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 004017c0  unit: CAboutRobloxDialog  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004017c0
//
// 004017c0  803db380e50000       cmp byte ptr [0xe580b3], 0
// 004017c7  7442                 je 0x40180b
// 004017c9  813dfc62e1009a020000 cmp dword ptr [0xe162fc], 0x29a
// 004017d3  7436                 je 0x40180b
// 004017d5  a19c80e500           mov eax, dword ptr [0xe5809c]
// 004017da  85c0                 test eax, eax
// 004017dc  7418                 je 0x4017f6
// 004017de  68cf000000           push 0xcf
// 004017e3  68a82fb400           push 0xb42fa8
// 004017e8  68902fb400           push 0xb42f90
// 004017ed  ffd0                 call eax
// 004017ef  83c40c               add esp, 0xc
// 004017f2  84c0                 test al, al
// 004017f4  7515                 jne 0x40180b
// 004017f6  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 004017fd  68202fb400           push 0xb42f20
// 00401802  50                   push eax
// 00401803  e8880a5700           call 0x972290
// 00401808  83c408               add esp, 8
// 0040180b  833d4cdbb80000       cmp dword ptr [0xb8db4c], 0
// 00401812  7505                 jne 0x401819
// 00401814  e967dc2700           jmp 0x67f480
// 00401819  6830164000           push 0x401630
// 0040181e  680463e100           push 0xe16304
// 00401823  e878fdffff           call 0x4015a0
// 00401828  83c408               add esp, 8
// 0040182b  e990faffff           jmp 0x4012c0

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

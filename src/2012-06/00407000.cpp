// from server: 100% by Xemicl
// from server: 100% by tester
// roc 2012-06 00574aa0  unit: AsyncResult  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00574aa0
//
// 00574aa0  803db380e50000       cmp byte ptr [0xe580b3], 0
// 00574aa7  7442                 je 0x574aeb
// 00574aa9  813db846e2009a020000 cmp dword ptr [0xe246b8], 0x29a
// 00574ab3  7436                 je 0x574aeb
// 00574ab5  a19c80e500           mov eax, dword ptr [0xe5809c]
// 00574aba  85c0                 test eax, eax
// 00574abc  7418                 je 0x574ad6
// 00574abe  68cf000000           push 0xcf
// 00574ac3  68a82fb400           push 0xb42fa8
// 00574ac8  68902fb400           push 0xb42f90
// 00574acd  ffd0                 call eax
// 00574acf  83c40c               add esp, 0xc
// 00574ad2  84c0                 test al, al
// 00574ad4  7515                 jne 0x574aeb
// 00574ad6  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 00574add  68202fb400           push 0xb42f20
// 00574ae2  50                   push eax
// 00574ae3  e8a8d73f00           call 0x972290
// 00574ae8  83c408               add esp, 8
// 00574aeb  833d105bbc0000       cmp dword ptr [0xbc5b10], 0
// 00574af2  7505                 jne 0x574af9
// 00574af4  e987a91000           jmp 0x67f480
// 00574af9  68d01e5700           push 0x571ed0
// 00574afe  681447e200           push 0xe24714
// 00574b03  e898cae8ff           call 0x4015a0
// 00574b08  83c408               add esp, 8
// 00574b0b  e920b9ffff           jmp 0x570430

extern "C" {
    int __cdecl sub_972290(unsigned char, const char*);
    int __cdecl sub_4015a0(const char*, const char*);
    int __cdecl sub_67f480();
    int __cdecl sub_570430();
}

extern unsigned char g_e580b3;
extern int g_e246b8;
extern int g_e5809c;
extern int g_bc5b10;

extern const char g_b42f20[];
extern const char g_b42f90[];
extern const char g_b42fa8[];
extern const char g_e24714[];
extern const char g_571ed0[];

struct AsyncResult {
    void construct();
};

void AsyncResult::construct()
{
    if (g_e580b3 != 0) {
        if (g_e246b8 != 0x29a) {
            int f = g_e5809c;
            if (f != 0) {
                if (((char (__cdecl*)(const char*, const char*, int))f)(g_b42f90, g_b42fa8, 0xcf) != 0) {
                    goto after;
                }
            }
            sub_972290(g_e580b3, g_b42f20);
        }
    }
after:
    if (g_bc5b10 == 0) {
        sub_67f480();
        return;
    }
    sub_4015a0(g_e24714, g_571ed0);
    sub_570430();
}

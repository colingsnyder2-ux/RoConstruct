// from server: 97% by Intel
// roc 2012-06 00574950  unit: AsyncResult  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00574950
//
// 00574950  803db380e50000       cmp byte ptr [0xe580b3], 0
// 00574957  7442                 je 0x57499b
// 00574959  813dac46e2009a020000 cmp dword ptr [0xe246ac], 0x29a
// 00574963  7436                 je 0x57499b
// 00574965  a19c80e500           mov eax, dword ptr [0xe5809c]
// 0057496a  85c0                 test eax, eax
// 0057496c  7418                 je 0x574986
// 0057496e  68cf000000           push 0xcf
// 00574973  68a82fb400           push 0xb42fa8
// 00574978  68902fb400           push 0xb42f90
// 0057497d  ffd0                 call eax
// 0057497f  83c40c               add esp, 0xc
// 00574982  84c0                 test al, al
// 00574984  7515                 jne 0x57499b
// 00574986  0fb605b380e500       movzx eax, byte ptr [0xe580b3]
// 0057498d  68202fb400           push 0xb42f20
// 00574992  50                   push eax
// 00574993  e8f8d83f00           call 0x972290
// 00574998  83c408               add esp, 8
// 0057499b  833d005bbc0000       cmp dword ptr [0xbc5b00], 0
// 005749a2  7505                 jne 0x5749a9
// 005749a4  e9d7aa1000           jmp 0x67f480
// 005749a9  68a01e5700           push 0x571ea0
// 005749ae  680847e200           push 0xe24708
// 005749b3  e8e8cbe8ff           call 0x4015a0
// 005749b8  83c408               add esp, 8
// 005749bb  e920b9ffff           jmp 0x5702e0

extern "C" int __cdecl sub_972290(int, int);
extern "C" int __cdecl sub_4015a0(int, int);
extern "C" void __cdecl sub_67f480();
extern "C" void __cdecl sub_5702e0();

typedef int (__cdecl *CallbackType)(int, int, int);

unsigned char g_flag_e580b3;
int g_value_e246ac;
CallbackType g_callback_e5809c;
int g_global_bc5b00;

void sub_574950()
{
    if (!g_flag_e580b3)
        goto LABEL_9B;

    if (g_value_e246ac == 0x29A)
        goto LABEL_9B;

    CallbackType cb = g_callback_e5809c;
    if (!cb)
        goto LABEL_86;

    if (cb(0xB42F90, 0xB42FA8, 0xCF))
        goto LABEL_9B;

LABEL_86:
    sub_972290(0xB42F20, g_flag_e580b3);

LABEL_9B:
    if (!g_global_bc5b00)
        sub_67f480();
    else
    {
        sub_4015a0(0xE24708, 0x571EA0);
        sub_5702e0();
    }
}

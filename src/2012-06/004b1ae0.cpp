// from server: 85% by Intel




extern "C" int __cdecl sub_972290(int, int);
extern "C" int __stdcall sub_4015a0(int, int);
extern "C" void __cdecl sub_67f480();
extern "C" void __cdecl sub_4b12d0();

int g_e580b3;
int g_e5809c;
int g_e1bdac;
int g_e1bdb8;
int g_bb6490;

void sub_4b1ae0()
{
    if (!g_e580b3)
        goto L_4b1b2b;

    if (g_e1bdac == 0x29a)
        goto L_4b1b2b;

    int (__cdecl *func)(int, int, int) = (int (__cdecl *)(int, int, int))g_e5809c;
    if (!func)
        goto L_4b1b16;

    if (func(0xb42fa8, 0xb42f90, 0xcf))
        goto L_4b1b2b;

L_4b1b16:
    sub_972290(0xb42f20, g_e580b3);

L_4b1b2b:
    if (!g_bb6490)
        sub_67f480();

    sub_4015a0(0x4b1790, g_e1bdb8);
    sub_4b12d0();
}

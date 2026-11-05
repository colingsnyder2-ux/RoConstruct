// from server: 100% by Viper
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

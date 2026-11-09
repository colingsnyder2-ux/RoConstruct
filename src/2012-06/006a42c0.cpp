// from server: 100% by tajop
extern "C" {
int __cdecl sub_8322c0(int, int);
int __cdecl sub_8323a0(int, int);
int __cdecl sub_831ce0(int, int);
int __cdecl sub_831b00(int, int);
int __cdecl sub_832b40(int, int);
int __cdecl sub_832340(int, int, int);
int __cdecl sub_8326d0(int, int);
int __cdecl sub_831cb0(int, int);
int __cdecl sub_8325e0(int, int);
int __cdecl sub_831b50(int, int);
int __cdecl sub_972290(int, int);
}

extern unsigned char g_e580b3;
extern int g_e5809c;
extern int g_de13fc;

struct VScriptContext {
    static void __cdecl FactoryProduct(int, int);
};

void VScriptContext::FactoryProduct(int a2, int a3) {
    int esi = a2;
    int edi;
    sub_8322c0(esi, 0x6a42c0);
    sub_8323a0(esi, -10000);
    if (g_e580b3 != 0) {
        if (sub_831ce0(esi, -1) == 0) {
            int eax = g_e5809c;
            if (eax != 0) {
                if (((char (__cdecl *)(int, int, int))eax)(0xb9450c, 0xb94520, 0xfa) != 0) {
                    goto skip;
                }
            }
            sub_972290((int)g_e580b3, 0xb94498);
        }
    }
skip:
    edi = a3;
    sub_8322c0(esi, edi);
    sub_8323a0(esi, -2);
    if (sub_831ce0(esi, -1) == 0) {
        sub_831b00(esi, -2);
        int *p = (int *)sub_832b40(esi, 4);
        if (p != 0) {
            *p = edi;
        }
        sub_832340(esi, -10000, g_de13fc);
        sub_8326d0(esi, -2);
        sub_8322c0(esi, edi);
        sub_831cb0(esi, -2);
        sub_8325e0(esi, -4);
    }
    sub_831b50(esi, -2);
}

// from server: 98% by atomic.potato
struct S {
    char pad0[4];
    int field4;
    char pad8[0x60];
    int field68;
    char pad6c[0x18];
    int field84;
    void f();
};

extern unsigned char g_e580b3;
extern int g_e5809c;
extern int g_bb32c8;
extern int g_bb32b0;
extern int g_bb3238;

extern "C" int __cdecl sub_972290(int a, int b);

void S::f() {
    int v = 0xb839a4;
    field84 = v;
    field68 = v;
    if (g_e580b3 != 0) {
        if (field4 != -1) {
            char (*fp)(int, int, int) = (char (*)(int, int, int))g_e5809c;
            if (fp != 0) {
                if (fp(0x16, (int)&g_bb32c8, (int)&g_bb32b0) != 0) {
                    return;
                }
            }
            sub_972290(g_e580b3, (int)&g_bb3238);
        }
    }
}

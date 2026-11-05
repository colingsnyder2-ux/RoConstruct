// from server: 32% by atomic.potato
extern "C" void __cdecl func_00705780();
extern "C" void __cdecl func_006cab60();
extern "C" void __cdecl func_009831f5();

extern unsigned char g_e42264;
extern void* g_bea288;
extern void* g_b1af10;

struct S {
    void f();
};

void S::f()
{
    if (!(g_e42264 & 1)) {
        g_e42264 |= 1;
        struct Local {
            char a;
            char b;
            int c;
            int d;
        } local;
        local.a = 0;
        local.b = 0;
        local.c = 0;
        local.d = 0x1b;
        func_00705780();
        func_006cab60();
        func_009831f5();
    }
}

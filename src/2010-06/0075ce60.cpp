// from server: 23% by atomic.potato
struct P_func_00679420 { void g(); };
struct S_func_00679420 {
    char pad[244];
    P_func_00679420* m_p;
    void f();
};

extern "C" void* __cdecl func_007a79a0(unsigned int size);
extern "C" void __cdecl func_0074b400();
extern "C" void __cdecl func_0075dca0();
extern "C" void __cdecl func_0075cd70();
extern "C" void __cdecl func_0075cdd0();

struct S_func_0075ce60 {
    void* __cdecl f(int a, int b, int c, int d, int e, int f);
};

void* S_func_0075ce60::f(int a, int b, int c, int d, int e, int f)
{
    if (a == 6) {
        char* p = (char*)func_007a79a0(0xd0);
        if (p) {
            func_0075dca0();
            *(void**)p = (void*)0xa52034;
            *(void**)(p + 0x20) = (void*)0xa52014;
            return p;
        }
        return 0;
    }
    float v = 0.0f;
    S_func_00679420* s1 = (S_func_00679420*)b;
    S_func_00679420* s2 = (S_func_00679420*)c;
    s1->f();
    s2->f();
    func_0074b400();
    if (d == 8) {
        char* p = (char*)func_007a79a0(0xdc);
        if (p) {
            func_0075cd70();
            return p;
        }
    }
    else if (d == 7) {
        char* p = (char*)func_007a79a0(0xdc);
        if (p) {
            func_0075cdd0();
            return p;
        }
    }
    return 0;
}

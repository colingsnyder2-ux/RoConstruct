// from server: 37% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall G1_func_00b22644();
extern "C" void __stdcall G1_func_00b2263c();

struct Str {
    void* pad0;
    char pad[16];
    Str();
    Str(const Str&);
    ~Str();
};

struct Inner {
    void* vptr;
    long ref1;
    long ref2;
};

struct S {
    void f(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
    void g1(int);
    void g2(int);
};

void S::g1(int) {}
void S::g2(int) {}

void S::f(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
    Str s1;
    Str s2;
    Inner* p;
    G1_func_00b22644();
    p = 0;
    if (p) {
        _InterlockedExchangeAdd(&p->ref1, 1);
    }
    g1(a);
    g2(b);
    G1_func_00b22644();
    if (p) {
        _InterlockedExchangeAdd(&p->ref1, 1);
    }
    g2(c);
    if (p) {
        if (_InterlockedExchangeAdd(&p->ref1, -1) == 1) {
            ((void (__thiscall*)(Inner*))p->vptr)(p);
            if (_InterlockedExchangeAdd(&p->ref2, -1) == 1) {
                ((void (__thiscall*)(Inner*))p->vptr)(p);
            }
        }
    }
    G1_func_00b2263c();
}

// from server: 19% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

struct Obj {
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
};

struct S {
    char pad0[4];
    int f(int, int, int, int);
};

int S::f(int a, int b, int c, int d) {
    Inner* p = (Inner*)a;
    Inner* q = 0;
    if (p) {
        q = p;
        p->f2();
    }
    Obj* o = (Obj*)b;
    if (o) {
        _InterlockedExchangeAdd((volatile long*)((char*)o + 4), 1);
    }
    return 0;
}

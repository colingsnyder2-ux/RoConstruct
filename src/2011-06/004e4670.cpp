// from server: 48% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

struct Obj {
    virtual void g1();
    virtual void g2();
    virtual int g3();
};

struct S {
    int field0;
    int f(Obj* a, Inner* b);
};

int S::f(Obj* a, Inner* b)
{
    int r = a->g3();
    this->field0 += r;
    if (b) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)b + 4), -1) == 1) {
            b->f1();
            if (_InterlockedExchangeAdd((volatile long*)((char*)b + 8), -1) == 1) {
                b->f2();
            }
        }
    }
    return this->field0;
}

// from server: 59% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_49CB50(void*, void*);

struct Inner {
    char pad[0x1c];
    volatile long refcount;
};

struct Outer {
    virtual void f();
};

struct Vtbl {
    char pad[0x64];
    void (__thiscall *fn)(Outer*, Inner**);
};

struct S {
    void method();
};

void S::method() {
    Outer* o = (Outer*)this;
    Vtbl* vt = *(Vtbl**)o;
    Inner* p;
    vt->fn(o, &p);
    if (_InterlockedExchangeAdd(&p->refcount, -1) == 1) {
        sub_49CB50(&p, (void*)0x49c690);
    }
}

// from server: 33% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Sub10 {
    void destroy();
};

struct Sub0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

struct Inner {
    long ref4;
    long ref8;
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

struct S {
    void* vtbl;
    Inner* ptr8;
    Sub10* ptrC;
    char pad10[4];
    void sub10();
    void destroy();
};

void S::sub10() {
    Sub10* p = ptrC;
    if (p) {
        p->destroy();
    }
}

void S::destroy() {
    vtbl = (void*)0x787f88;
    if (ptrC) {
        sub10();
    }
    ((Sub10*)((char*)this + 0x10))->destroy();
    Inner* p = ptr8;
    if (p) {
        if (_InterlockedExchangeAdd(&p->ref4, -1) == 1) {
            p->v0();
            if (_InterlockedExchangeAdd(&p->ref8, -1) == 1) {
                p->v1();
            }
        }
    }
    vtbl = (void*)0x787f68;
}

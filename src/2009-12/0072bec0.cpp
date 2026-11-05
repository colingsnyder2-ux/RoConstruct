// from server: 32% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void (__thiscall *dtor)(Inner*);
    void (__thiscall *deleter)(Inner*);
    long ref;
};

struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

struct S : Base {
    char pad[0x1c];
    void* field20;
    void* field24;
    Inner* field28;
    S(void* a, void* b, Inner* c);
};

S::S(void* a, void* b, Inner* c) {
    field20 = a;
    field24 = b;
    field28 = c;
    if (c) {
        _InterlockedExchangeAdd(&c->ref, 1);
    }
    if (c) {
        if (_InterlockedExchangeAdd(&c->ref, -1) == 1) {
            c->dtor(c);
            if (_InterlockedExchangeAdd(&c->ref, -1) == 1) {
                c->deleter(c);
            }
        }
    }
}

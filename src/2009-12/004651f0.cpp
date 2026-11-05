// from server: 57% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[0x18];
};

struct Holder {
    Inner* p;
    char pad4[4];
    long ref;
};

struct Outer {
    char pad0[4];
    long ref;
    char pad8[4];
    virtual void v0();
    virtual void v1();
};

extern Holder* __cdecl getHolder(Holder** out);

struct S {
    void* f(void* out);
};

void* S::f(void* out) {
    Holder* h = 0;
    getHolder(&h);
    Inner* inner = h ? (Inner*)((char*)h->p + 0x18) : 0;
    *(void**)out = inner;
    void* q = *(void**)((char*)h + 4);
    *(void**)((char*)out + 4) = q;
    if (q) {
        _InterlockedExchangeAdd((volatile long*)((char*)q + 4), 1);
    }
    Outer* o = *(Outer**)((char*)out + 0x10);
    if (o) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)o + 4), -1) == 1) {
            o->v0();
            if (_InterlockedExchangeAdd((volatile long*)((char*)o + 8), -1) == 1) {
                o->v1();
            }
        }
    }
    return out;
}

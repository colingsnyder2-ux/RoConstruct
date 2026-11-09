// from server: 71% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[0x18];
};

struct RefCounted {
    void* vptr;
    long refcount;
};

struct Holder {
    Inner* ptr;
    RefCounted* ref;
};

struct Src {
    char pad0[4];
    long refcount;
    char pad1[4];
    long refcount2;
};

extern Holder* __cdecl getHolder(Holder* out);

struct Factory {
    Holder* create(Holder* out);
};

Holder* Factory::create(Holder* out) {
    Holder tmp;
    tmp.ptr = 0;
    Holder* h = getHolder(&tmp);
    Inner* p = h->ptr;
    if (p) {
        p = (Inner*)((char*)p + 0x18);
    } else {
        p = 0;
    }
    out->ptr = p;
    RefCounted* r = h->ref;
    out->ref = r;
    if (r) {
        _InterlockedExchangeAdd(&r->refcount, 1);
    }
    Src* s = (Src*)tmp.ptr;
    tmp.ref = 0;
    tmp.ptr = (Inner*)1;
    if (s) {
        if (_InterlockedExchangeAdd(&s->refcount, -1) == 1) {
            void** vt = *(void***)s;
            ((void (__thiscall*)(Src*))vt[1])(s);
            if (_InterlockedExchangeAdd(&s->refcount2, -1) == 1) {
                void** vt2 = *(void***)s;
                ((void (__thiscall*)(Src*))vt2[2])(s);
            }
        }
    }
    return out;
}

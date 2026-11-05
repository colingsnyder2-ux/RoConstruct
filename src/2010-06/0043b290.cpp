// from server: 65% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
};

struct Holder {
    void* ptr;
    RefCounted* ref;
};

extern Holder* __cdecl getHolder(Holder* out);

struct Creator {
    Holder* __thiscall create(Holder* out);
};

Holder* Creator::create(Holder* out) {
    Holder tmp;
    tmp.ptr = 0;
    Holder* h = getHolder(&tmp);
    void* p = h->ptr;
    if (p) {
        p = (char*)p + 0x18;
    } else {
        p = 0;
    }
    out->ptr = p;
    RefCounted* r = h->ref;
    out->ref = r;
    if (r) {
        _InterlockedExchangeAdd(&r->ref1, 1);
    }
    RefCounted* old = tmp.ref;
    if (old) {
        if (_InterlockedExchangeAdd(&old->ref1, -1) == 1) {
            old->vptr;
            ((void (__thiscall*)(RefCounted*))((void**)old->vptr)[1])(old);
            if (_InterlockedExchangeAdd(&old->ref2, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))((void**)old->vptr)[2])(old);
            }
        }
    }
    return out;
}

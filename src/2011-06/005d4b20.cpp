// from server: 58% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
};

struct Holder {
    void* ptr;
    RefCounted* ref;
};

extern "C" Holder* __cdecl get_holder(Holder* out);

struct S {
    Holder* f(Holder* out);
};

Holder* S::f(Holder* out) {
    Holder tmp;
    tmp.ptr = 0;
    Holder* h = get_holder(&tmp);
    void* p = h->ptr;
    if (p != 0) {
        out->ptr = (char*)p + 0x18;
    } else {
        out->ptr = 0;
    }
    RefCounted* r = h->ref;
    out->ref = r;
    if (r != 0) {
        _InterlockedExchangeAdd(&r->refcount, 1);
    }
    RefCounted* old = tmp.ref;
    if (old != 0) {
        if (_InterlockedExchangeAdd(&old->refcount, -1) == 1) {
            void** vt = *(void***)old;
            ((void (__thiscall*)(RefCounted*))vt[1])(old);
            if (_InterlockedExchangeAdd((volatile long*)((char*)old + 8), -1) == 1) {
                void** vt2 = *(void***)old;
                ((void (__thiscall*)(RefCounted*))vt2[2])(old);
            }
        }
    }
    return out;
}

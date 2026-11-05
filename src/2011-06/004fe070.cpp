// from server: 58% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void** vptr;
    volatile long ref1;
    volatile long ref2;
};

struct Holder {
    void* ptr;
    RefCounted* ref;
};

extern "C" void* __cdecl sub_4fdff0(void** out);

struct S {
    Holder* f(Holder* out);
};

Holder* S::f(Holder* out) {
    void* tmp = 0;
    sub_4fdff0(&tmp);
    void* p = tmp;
    void* base;
    if (p != 0) {
        base = (char*)p + 0x18;
    } else {
        base = 0;
    }
    out->ptr = base;
    RefCounted* r = *(RefCounted**)((char*)p + 4);
    out->ref = r;
    if (r != 0) {
        _InterlockedExchangeAdd(&r->ref1, 1);
    }
    RefCounted* old = out->ref;
    if (old != 0) {
        if (_InterlockedExchangeAdd(&old->ref1, -1) == 1) {
            void** vt = old->vptr;
            ((void (__thiscall*)(RefCounted*))vt[1])(old);
            if (_InterlockedExchangeAdd(&old->ref2, -1) == 1) {
                void** vt2 = old->vptr;
                ((void (__thiscall*)(RefCounted*))vt2[2])(old);
            }
        }
    }
    return out;
}

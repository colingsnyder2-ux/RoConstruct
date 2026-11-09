// from server: 46% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
    long weakrefcount;
};

struct Holder {
    RefCounted* ptr;
    RefCounted* ptr2;
};

extern "C" void* __cdecl sub_5422C0(void** out);

struct Creator {
    Holder* __stdcall Create(Holder* out);
};

Holder* __stdcall Creator::Create(Holder* out) {
    void* tmp = 0;
    sub_5422C0(&tmp);
    RefCounted* p = *(RefCounted**)tmp;
    if (p) {
        p = (RefCounted*)((char*)p + 0x18);
    } else {
        p = 0;
    }
    out->ptr = p;
    RefCounted* q = *(RefCounted**)((char*)tmp + 4);
    out->ptr2 = q;
    if (q) {
        _InterlockedExchangeAdd(&q->refcount, 1);
    }
    RefCounted* old = *(RefCounted**)&tmp;
    if (old) {
        if (_InterlockedExchangeAdd(&old->refcount, -1) != 1) {
            old->vptr;
            ((void (__thiscall*)(RefCounted*))((void**)old->vptr)[1])(old);
            if (_InterlockedExchangeAdd(&old->weakrefcount, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))((void**)old->vptr)[2])(old);
            }
        }
    }
    return out;
}

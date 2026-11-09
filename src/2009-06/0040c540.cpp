// from server: 44% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vfptr;
    volatile long refcount;
};

struct Holder {
    void* ptr;
    RefCounted* ref;
};

struct Src {
    void* pad0;
    volatile long refcount;
    volatile long refcount2;
};

extern "C" void* __cdecl sub_40C190(void** out);

struct Creator {
    Holder* __thiscall make(Holder* out);
};

Holder* __thiscall Creator::make(Holder* out) {
    void* tmp = 0;
    sub_40C190(&tmp);
    void* p = tmp;
    void* ecx = 0;
    if (p != 0) {
        ecx = (char*)p + 0x14;
    }
    out->ptr = ecx;
    RefCounted* r = *(RefCounted**)((char*)p + 4);
    out->ref = r;
    if (r != 0) {
        _InterlockedExchangeAdd(&r->refcount, 1);
    }
    Src* s = *(Src**)((char*)&tmp + 0x0);
    if (s != 0) {
        if (_InterlockedExchangeAdd(&s->refcount, -1) == 1) {
            void** vt = *(void***)s;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(s);
            if (_InterlockedExchangeAdd(&s->refcount2, -1) == 1) {
                void** vt2 = *(void***)s;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(s);
            }
        }
    }
    return out;
}

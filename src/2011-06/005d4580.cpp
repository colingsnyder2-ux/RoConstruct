// from server: 53% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
};

struct Holder {
    RefCounted* ptr;
    RefCounted* ptr2;
};

extern "C" void* __cdecl sub_5D4500(void** out);

struct Creator {
    Holder* __stdcall Create(Holder* out);
};

Holder* __stdcall Creator::Create(Holder* out) {
    void* tmp = 0;
    void* r = sub_5D4500(&tmp);
    RefCounted* p = *(RefCounted**)r;
    if (p) {
        p = (RefCounted*)((char*)p + 0x18);
    } else {
        p = 0;
    }
    out->ptr = p;
    RefCounted* q = *(RefCounted**)((char*)r + 4);
    out->ptr2 = q;
    if (q) {
        _InterlockedExchangeAdd(&q->ref1, 1);
    }
    RefCounted* s = *(RefCounted**)&tmp;
    if (s) {
        if (_InterlockedExchangeAdd(&s->ref1, -1) == 1) {
            void (*f1)(RefCounted*) = *(void (**)(RefCounted*))(*(void**)s);
            f1(s);
            if (_InterlockedExchangeAdd(&s->ref2, -1) == 1) {
                void (*f2)(RefCounted*) = *(void (**)(RefCounted*))((char*)*(void**)s + 8);
                f2(s);
            }
        }
    }
    return out;
}

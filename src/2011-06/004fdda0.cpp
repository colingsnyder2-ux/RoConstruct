// from server: 58% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long ref;
    long weak;
};

struct Holder {
    void* ptr;
    RefCounted* ref;
};

extern "C" void* __cdecl sub_4fdd20(void** out);

struct S {
    Holder* f(Holder* out);
};

Holder* S::f(Holder* out) {
    void* tmp = 0;
    void* r = sub_4fdd20(&tmp);
    RefCounted* rc = 0;
    void* p = *(void**)r;
    if (p) rc = (RefCounted*)((char*)p + 0x18);
    out->ptr = rc;
    RefCounted* r2 = *(RefCounted**)((char*)r + 4);
    out->ref = r2;
    if (r2) {
        _InterlockedExchangeAdd(&r2->ref, 1);
    }
    RefCounted* old = (RefCounted*)tmp;
    if (old) {
        if (_InterlockedExchangeAdd(&old->ref, -1) == 1) {
            void** vt = *(void***)old;
            ((void(__thiscall*)(RefCounted*))vt[1])(old);
            if (_InterlockedExchangeAdd(&old->weak, -1) == 1) {
                void** vt2 = *(void***)old;
                ((void(__thiscall*)(RefCounted*))vt2[2])(old);
            }
        }
    }
    return out;
}

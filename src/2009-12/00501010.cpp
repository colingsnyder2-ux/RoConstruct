// from server: 57% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_4F8DA0(void**);

struct RefCounted {
    void** vptr;
    long refcount;
};

struct Holder {
    void* ptr;
    RefCounted* ref;
};

struct S {
    Holder* __stdcall f(Holder* out);
};

Holder* __stdcall S::f(Holder* out) {
    void* tmp = 0;
    void** res = (void**)sub_4F8DA0(&tmp);
    RefCounted* rc = 0;
    void* p = *res;
    if (p) {
        rc = (RefCounted*)((char*)p + 0x18);
    }
    out->ptr = rc;
    RefCounted* r2 = (RefCounted*)res[1];
    out->ref = r2;
    if (r2) {
        _InterlockedExchangeAdd(&r2->refcount, 1);
    }
    RefCounted* esi = (RefCounted*)tmp;
    if (esi) {
        if (_InterlockedExchangeAdd(&esi->refcount, -1) == 1) {
            void** vt = (void**)esi->vptr;
            ((void (__thiscall*)(RefCounted*))vt[1])(esi);
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 8), -1) == 1) {
                void** vt2 = (void**)esi->vptr;
                ((void (__thiscall*)(RefCounted*))vt2[2])(esi);
            }
        }
    }
    return out;
}

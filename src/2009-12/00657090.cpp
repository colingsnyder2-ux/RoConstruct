// from server: 43% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
};

struct Handle {
    void* ptr;
    RefCounted* ref;
};

struct Creator {
    Handle* __thiscall create(Handle* out);
};

extern "C" Handle* __cdecl sub_657010(Handle* out);

Handle* __thiscall Creator::create(Handle* out) {
    Handle tmp;
    tmp.ptr = 0;
    tmp.ref = 0;
    sub_657010(&tmp);
    void* p = tmp.ptr;
    if (p) {
        out->ptr = (char*)p + 0x18;
    } else {
        out->ptr = 0;
    }
    out->ref = tmp.ref;
    if (out->ref) {
        _InterlockedExchangeAdd(&out->ref->ref1, 1);
    }
    RefCounted* r = tmp.ref;
    if (r) {
        if (_InterlockedExchangeAdd(&r->ref1, -1) == 1) {
            void** vt = (void**)r->vptr;
            ((void (__thiscall*)(RefCounted*))vt[1])(r);
            if (_InterlockedExchangeAdd(&r->ref2, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))vt[2])(r);
            }
        }
    }
    return out;
}

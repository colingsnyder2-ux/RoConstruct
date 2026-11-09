// from server: 64% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
    long weakrefcount;
};

struct Holder {
    void* ptr;
    RefCounted* ref;
};

extern "C" void* __cdecl sub_5de0d0(void** out);

struct Factory {
    Holder* Create(Holder* result);
};

Holder* Factory::Create(Holder* result) {
    void* tmp = 0;
    void** p = (void**)sub_5de0d0(&tmp);
    void* obj = *p;
    RefCounted* rc;
    if (obj) {
        rc = (RefCounted*)((char*)obj + 0x18);
    } else {
        rc = 0;
    }
    result->ptr = rc;
    RefCounted* r2 = (RefCounted*)p[1];
    result->ref = r2;
    if (r2) {
        _InterlockedExchangeAdd(&r2->refcount, 1);
    }
    RefCounted* old = (RefCounted*)tmp;
    if (old) {
        if (_InterlockedExchangeAdd(&old->refcount, -1) == 1) {
            void** vt = (void**)old->vptr;
            ((void (__thiscall*)(RefCounted*))vt[1])(old);
            if (_InterlockedExchangeAdd(&old->weakrefcount, -1) == 1) {
                void** vt2 = (void**)old->vptr;
                ((void (__thiscall*)(RefCounted*))vt2[2])(old);
            }
        }
    }
    return result;
}

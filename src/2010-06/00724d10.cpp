// from server: 39% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __stdcall MSVCR90_type_info_equals(const void*, const void*);

struct RefCounted {
    void** vptr;
    long refcount;
    long weakrefcount;
};

struct Holder {
    void* p0;
    RefCounted* p1;
};

struct TypeInfoHolder {
    const void* p0;
    char b4;
    char b5;
};

struct BindT {
    void* p0;
    RefCounted* p1;
};

extern "C" int __stdcall type_info_equals(const void*, const void*);

struct VYieldFunctionStateObject {
    void* p0;
    RefCounted* p1;
};

struct sp_counted_impl_p {
    void* p0;
    RefCounted* p1;
};

struct S {
};

void __cdecl f(void* dst, const void* src, int op)
{
    if (op == 0 || op == 1) {
        Holder* d = (Holder*)dst;
        const Holder* s = (const Holder*)src;
        if (d) {
            d->p0 = s->p0;
            d->p1 = s->p1;
            if (d->p1) {
                _InterlockedExchangeAdd(&d->p1->refcount, 1);
            }
        }
        if (op == 1) {
            RefCounted* r = s->p1;
            if (r) {
                if (_InterlockedExchangeAdd(&r->refcount, -1) == 1) {
                    ((void (__stdcall*)(RefCounted*))r->vptr[1])(r);
                    if (_InterlockedExchangeAdd(&r->weakrefcount, -1) == 1) {
                        ((void (__stdcall*)(RefCounted*))r->vptr[2])(r);
                    }
                }
            }
        }
        return;
    }
    if (op == 2) {
        const Holder* s = (const Holder*)src;
        RefCounted* r = s->p1;
        if (r) {
            if (_InterlockedExchangeAdd(&r->refcount, -1) == 1) {
                ((void (__stdcall*)(RefCounted*))r->vptr[1])(r);
                if (_InterlockedExchangeAdd(&r->weakrefcount, -1) == 1) {
                    ((void (__stdcall*)(RefCounted*))r->vptr[2])(r);
                }
            }
        }
        return;
    }
    if (op == 3) {
        TypeInfoHolder* d = (TypeInfoHolder*)dst;
        const void* ti = *(const void**)src;
        int eq = type_info_equals(ti, (const void*)0xbe2928);
        d->p0 = eq ? (const void*)0xbe2928 : 0;
        return;
    }
    TypeInfoHolder* d = (TypeInfoHolder*)dst;
    d->p0 = (const void*)0xbe2928;
    d->b4 = 0;
    d->b5 = 0;
}

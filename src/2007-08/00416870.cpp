// from server: 52% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
};

struct Inner {
    void* vptr;
    long refcount;
    long weakrefcount;
};

struct Holder {
    int a;
    int b;
    int c;
    Inner* inner;
    int e;
};

struct Target {
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

Target* g_ret;

Holder* __cdecl clone(Holder* src)
{
    if (src != 0) {
        Holder* p = (Holder*)operator_new(0x18);
        if (p == 0)
            return 0;
        p->a = src->a;
        p->b = src->b;
        p->c = src->c;
        p->inner = src->inner;
        if (p->inner != 0) {
            _InterlockedExchangeAdd(&p->inner->refcount, 1);
        }
        p->e = src->e;
        return p;
    } else {
        Inner* inner = src->inner;
        if (inner != 0) {
            if (_InterlockedExchangeAdd(&inner->refcount, -1) == 1) {
                void (*fn)(Inner*) = *(void (**)(Inner*))((char*)inner->vptr + 4);
                fn(inner);
                if (_InterlockedExchangeAdd(&inner->weakrefcount, -1) == 1) {
                    void (*fn2)(Inner*) = *(void (**)(Inner*))((char*)inner->vptr + 8);
                    fn2(inner);
                }
            }
        }
        operator_delete(src);
        return 0;
    }
}

// from server: 51% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int (__thiscall *MSVCR90_type_info_equals)(const void*, const void*);

struct RefCounted {
    void** vptr;
    char pad[8];
    volatile long ref1;
    volatile long ref2;
};

struct Holder {
    void* p0;
    void* p1;
    void* p2;
    RefCounted* ptr;
};

struct Slot {
    void* vptr;
    char b4;
    char b5;
};

void func_007edd10(int op, Holder* dst, Holder* src)
{
    if (op == 0 || op == 1) {
        if (dst) {
            dst->p0 = src->p0;
            dst->p1 = src->p1;
            dst->p2 = src->p2;
            dst->ptr = src->ptr;
            if (dst->ptr) {
                _InterlockedExchangeAdd(&dst->ptr->ref1, 1);
            }
        }
        if (op == 1) {
            RefCounted* r = src->ptr;
            if (r) {
                if (_InterlockedExchangeAdd(&r->ref1, -1) == 1) {
                    void** vt = r->vptr;
                    void (*f4)(RefCounted*) = (void (*)(RefCounted*))vt[1];
                    f4(r);
                    if (_InterlockedExchangeAdd(&r->ref2, -1) == 1) {
                        void (*f8)(RefCounted*) = (void (*)(RefCounted*))vt[2];
                        f8(r);
                    }
                }
            }
        }
        return;
    }
    if (op == 2) {
        RefCounted* r = src->ptr;
        if (r) {
            if (_InterlockedExchangeAdd(&r->ref1, -1) == 1) {
                void** vt = r->vptr;
                void (*f4)(RefCounted*) = (void (*)(RefCounted*))vt[1];
                f4(r);
                if (_InterlockedExchangeAdd(&r->ref2, -1) == 1) {
                    void (*f8)(RefCounted*) = (void (*)(RefCounted*))vt[2];
                    f8(r);
                }
            }
        }
        return;
    }
    if (op == 3) {
        void* a = dst->p0;
        int eq = MSVCR90_type_info_equals((void*)0xdd4418, a);
        dst->p0 = eq ? src->p0 : 0;
        return;
    }
    Slot* s = (Slot*)dst;
    s->vptr = (void*)0xdd4418;
    s->b4 = 0;
    s->b5 = 0;
}

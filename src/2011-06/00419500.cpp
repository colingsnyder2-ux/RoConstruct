// from server: 50% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct type_info {
    bool operator==(const type_info&) const;
};

struct VValue {
    void* vptr;
    char pad[4];
    void* ref;
};

struct RefCounted {
    void* vptr;
    long refcount;
    long weakcount;
};

extern "C" void* __stdcall sub_a40a50(void*);

void f(VValue* dst, VValue* src, int op) {
    if (op == 0 || op == 1) {
        if (dst) {
            dst->vptr = src->vptr;
            dst->pad[0] = src->pad[0];
            dst->pad[1] = src->pad[1];
            dst->pad[2] = src->pad[2];
            dst->pad[3] = src->pad[3];
            dst->ref = src->ref;
            if (dst->ref) {
                _InterlockedExchangeAdd((volatile long*)((char*)dst->ref + 4), 1);
            }
        }
        if (op == 1) {
            RefCounted* r = (RefCounted*)src->ref;
            if (r) {
                if (_InterlockedExchangeAdd(&r->refcount, -1) == 1) {
                    ((void (__thiscall*)(RefCounted*))r->vptr)(r);
                    if (_InterlockedExchangeAdd(&r->weakcount, -1) == 1) {
                        ((void (__thiscall*)(RefCounted*))((void**)r->vptr)[2])(r);
                    }
                }
            }
        }
    } else if (op == 2) {
        RefCounted* r = (RefCounted*)dst->ref;
        if (r) {
            if (_InterlockedExchangeAdd(&r->refcount, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))r->vptr)(r);
                if (_InterlockedExchangeAdd(&r->weakcount, -1) == 1) {
                    ((void (__thiscall*)(RefCounted*))((void**)r->vptr)[2])(r);
                }
            }
        }
    } else if (op == 3) {
        void* t = sub_a40a50((void*)0xc0b230);
        dst->vptr = (void*)((int)t & (int)src);
    } else {
        dst->vptr = (void*)0xc0b230;
        dst->pad[0] = 0;
        dst->pad[1] = 0;
    }
}

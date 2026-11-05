// from server: 44% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakCount;
};

struct Creator {
    void* vptr;
};

struct FactoryProduct {
    void* vptr;
};

extern "C" void __cdecl sub_41ADA0(void*);

void FactoryProduct_ctor(FactoryProduct* self, void* arg0, void* arg1, RefCounted* arg2, void* arg3)
{
    void* local[6];
    local[0] = arg0;
    local[1] = arg1;
    local[2] = 0;
    local[3] = arg2;
    if (arg2) {
        _InterlockedExchangeAdd(&arg2->refCount, 1);
    }
    local[4] = arg3;
    sub_41ADA0(local);
    if (arg2) {
        if (_InterlockedExchangeAdd(&arg2->refCount, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))((void**)arg2->vptr)[1])(arg2);
            if (_InterlockedExchangeAdd(&arg2->weakCount, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))((void**)arg2->vptr)[2])(arg2);
            }
        }
    }
}

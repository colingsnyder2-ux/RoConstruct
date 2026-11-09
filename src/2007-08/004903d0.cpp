// from server: 35% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakCount;
    void Release();
};

struct Obj {
    char pad[0x10];
};

struct Holder {
    void* ptr;
    void* pad;
};

extern "C" void __cdecl sub_417860(void*, void*);
extern "C" void __cdecl sub_40CC20(void*, void*, void*);
extern "C" void __cdecl sub_4900D0(void*, void*);
extern "C" void __cdecl sub_48A140(void*, void*, void*);
extern "C" void __cdecl sub_49A230(void*);

struct S {
    void* f(void* a, void* b, void* c, void* d);
};

void* S::f(void* a, void* b, void* c, void* d)
{
    Holder h;
    void* local;
    void* result;

    h.ptr = 0;
    h.pad = a;
    sub_417860(&h, a);
    sub_40CC20(&h, a, a);
    sub_4900D0(&local, &h);
    result = b;
    sub_48A140((char*)c + 0x10, &local, d);
    sub_49A230(&h);

    if (h.ptr) {
        RefCounted* rc = (RefCounted*)h.ptr;
        if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
            rc->Release();
            if (_InterlockedExchangeAdd(&rc->weakCount, -1) == 1) {
                rc->Release();
            }
        }
    }
    return result;
}

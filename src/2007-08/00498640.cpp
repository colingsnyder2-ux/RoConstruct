// from server: 37% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakRefCount;
};

struct Inner {
    char pad[0x10];
};

struct Outer {
    char pad0[0x10];
    Inner inner;
};

extern "C" void __cdecl sub_417860(void*, void*);
extern "C" void __cdecl sub_40CC20(void*, void*, void*);
extern "C" void __cdecl sub_498560(void*, void*);
extern "C" void __cdecl sub_493F90(void*, void*, void*, void*);
extern "C" void __cdecl sub_49A230(void*);

struct S {
    void f(void* a, void* b, void* c, void* d);
};

void S::f(void* a, void* b, void* c, void* d)
{
    void* local0 = 0;
    void* local1 = a;
    char buf[0x10];
    void* local2 = 0;
    void* local3 = 0;

    sub_417860(&local1, a);
    sub_40CC20(&local1, a, a);
    sub_498560(&local2, &local1);
    sub_493F90((char*)c + 0x10, b, &local2, d);
    sub_49A230(&local1);

    RefCounted* rc = (RefCounted*)local1;
    if (rc) {
        if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
            void** vt = *(void***)rc;
            ((void(__thiscall*)(void*))vt[1])(rc);
            if (_InterlockedExchangeAdd(&rc->weakRefCount, -1) == 1) {
                void** vt2 = *(void***)rc;
                ((void(__thiscall*)(void*))vt2[2])(rc);
            }
        }
    }
}

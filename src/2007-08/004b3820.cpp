// from server: 33% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakCount;
};

struct Inner {
    char pad[0x10];
};

struct Outer {
    void* field0;
    Inner inner;
};

struct S {
    char pad0[0x10];
    void* ptr;
    char pad1[0x10];
    int method(void* a, void* b, void* c, void* d);
};

extern "C" void __cdecl sub_417860(void*, void*);
extern "C" void __cdecl sub_40CC20(void*, void*, void*);
extern "C" void __cdecl sub_4B2EE0(void*, void*);
extern "C" void __cdecl sub_4AE020(void*, void*, void*, void*);
extern "C" void __cdecl sub_49A230(void*);

int S::method(void* a, void* b, void* c, void* d)
{
    void* local0 = 0;
    void* local1;
    void* local2;
    void* local3;
    void* local4;
    void* local5;
    void* local6;
    void* local7;
    void* local8;
    void* local9;
    void* local10;
    void* local11;
    void* local12;
    void* local13;
    void* local14;
    void* local15;

    local1 = a;
    sub_417860(&local1, a);
    sub_40CC20(&local1, a, a);
    sub_4B2EE0(&local1, &local0);
    sub_4AE020(c, &local1, b, d);
    sub_49A230(&local1);

    RefCounted* rc = (RefCounted*)local0;
    if (rc != 0) {
        if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
            void** vt = (void**)rc->vptr;
            void (*f1)(void*) = (void (*)(void*))vt[1];
            f1(rc);
            if (_InterlockedExchangeAdd(&rc->weakCount, -1) == 1) {
                void (*f2)(void*) = (void (*)(void*))vt[2];
                f2(rc);
            }
        }
    }
    return (int)b;
}

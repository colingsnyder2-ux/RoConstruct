// from server: 29% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void** vptr;
    long refcount1;
    long refcount2;
};

struct Inner {
    void* p0;
    void* p4;
};

struct S {
    char pad[0x28];
    Inner inner28;
    void* ptr34;
    void* ptr38;
    void* ptr3c;
    void* ptr40;

    void f();
};

extern "C" void __cdecl sub_55D210(void*);
extern "C" void __cdecl sub_402A60(void*);
extern "C" void __cdecl sub_40D550(void*);
extern "C" void __cdecl sub_450EC0(void);
extern "C" void __cdecl sub_49D670(void*, void*);
extern "C" void __cdecl sub_423240(void*, void*);
extern "C" void* __cdecl sub_410D40(void*);
extern "C" void __cdecl sub_5595A0(void*);

void S::f()
{
    void* tmp;
    sub_55D210(&tmp);
    ptr34 = *(void**)tmp;
    tmp = (char*)tmp + 4;
    sub_402A60(&tmp);
    sub_402A60(&ptr38);

    RefCounted* rc = (RefCounted*)tmp;
    if (rc) {
        if (_InterlockedExchangeAdd(&rc->refcount1, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))rc->vptr[1])(rc);
            if (_InterlockedExchangeAdd(&rc->refcount2, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))rc->vptr[2])(rc);
            }
        }
    }

    void* a = ptr34;
    void* b = ptr38;
    if (b) {
        _InterlockedExchangeAdd((volatile long*)((char*)b + 4), 1);
    }
    sub_40D550(&a);
    sub_450EC0();
    sub_49D670(&a, &tmp);
    ptr3c = *(void**)tmp;
    tmp = (char*)tmp + 4;
    sub_402A60(&tmp);
    sub_402A60(&ptr40);

    RefCounted* rc2 = (RefCounted*)tmp;
    if (rc2) {
        if (_InterlockedExchangeAdd(&rc2->refcount1, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))rc2->vptr[1])(rc2);
            if (_InterlockedExchangeAdd(&rc2->refcount2, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))rc2->vptr[2])(rc2);
            }
        }
    }

    void* p = *(void**)((char*)ptr34 + 0x188);
    if (p) {
        sub_423240((char*)p + 0x2d4, &inner28);
    }

    void* q = sub_410D40(ptr34);
    if (q) {
        sub_423240((char*)q + 0xe8, &inner28.p0);
    }

    sub_5595A0(&inner28);
}

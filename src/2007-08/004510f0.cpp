// from server: 36% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long ref1;
    long ref2;
};

struct Obj78 {
    void* field0;
};

struct Inner {
    void* vptr;
    int field4;
    int field8;
};

struct Vec {
    Inner* begin;
    Inner* end;
};

struct Big {
    char pad[0x104];
    Vec vec;
};

struct Arg {
    void* vptr;
};

struct S {
    char pad[0x78];
    Obj78* obj78;
    void method(Arg* arg);
};

extern "C" void* __cdecl sub_403800(void* out, void* in);
extern "C" void __cdecl sub_40D550(void* p);
extern "C" void* __cdecl sub_410D40(void* p);
extern "C" void __cdecl sub_5595A0(void* p);

void S::method(Arg* arg)
{
    void* tmp1;
    void* tmp2;
    void* tmp3;
    void* tmp4;
    RefCounted* rc;
    Big* big;
    int count;
    void* vptr;
    void (*fn)(void*, int);

    sub_403800(&tmp1, obj78);
    rc = (RefCounted*)tmp1;
    tmp2 = rc->vptr;
    tmp3 = (void*)rc->ref1;
    if (tmp3 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)tmp3 + 4), 1);
    }
    sub_40D550(&tmp4);

    if (tmp4 != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)tmp4 + 4), -1) == 1) {
            vptr = *(void**)tmp4;
            fn = *(void (**)(void*, int))((char*)vptr + 4);
            fn(tmp4, 1);
            if (_InterlockedExchangeAdd((volatile long*)((char*)tmp4 + 8), -1) == 1) {
                vptr = *(void**)tmp4;
                fn = *(void (**)(void*, int))((char*)vptr + 8);
                fn(tmp4, 1);
            }
        }
    }

    sub_403800(&tmp1, obj78);
    if (tmp1 != 0) {
        big = (Big*)sub_410D40(tmp1);
    } else {
        big = 0;
    }

    if (tmp2 != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)tmp2 + 4), -1) == 1) {
            vptr = *(void**)tmp2;
            fn = *(void (**)(void*, int))((char*)vptr + 4);
            fn(tmp2, 1);
            if (_InterlockedExchangeAdd((volatile long*)((char*)tmp2 + 8), -1) == 1) {
                vptr = *(void**)tmp2;
                fn = *(void (**)(void*, int))((char*)vptr + 8);
                fn(tmp2, 1);
            }
        }
    }

    count = 0;
    if (big->vec.begin != 0) {
        count = (int)((char*)big->vec.end - (char*)big->vec.begin) >> 3;
    }

    vptr = *(void**)arg;
    fn = *(void (**)(void*, int))vptr;
    fn(arg, count != 0);

    sub_5595A0(&tmp4);
}

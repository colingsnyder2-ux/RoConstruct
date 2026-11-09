// from server: 30% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void* vfptr;
    long ref1;
    long ref2;
};

struct Obj {
    void* vfptr;
    long ref1;
    long ref2;
};

struct Result {
    void* p0;
    void* p1;
    void* p2;
    void* p3;
    void* p4;
    void* p5;
};

extern "C" void __cdecl sub_413EC0(void*, void*);

struct S {
    Result* __thiscall f(Obj* a, Obj* b, Obj* c, Obj* d);
};

Result* __thiscall S::f(Obj* a, Obj* b, Obj* c, Obj* d)
{
    Result* r;
    void* tmp[6];
    void* local;
    int flag;

    flag = 0;
    tmp[0] = 0;
    tmp[1] = 0;
    tmp[2] = 0;
    tmp[3] = 0;
    tmp[4] = 0;
    tmp[5] = 0;

    if (d) {
        _InterlockedExchangeAdd(&d->ref1, 1);
    }

    sub_413EC0(&local, tmp);

    r = (Result*)tmp[0];
    r->p0 = tmp[1];
    r->p1 = tmp[2];
    r->p2 = tmp[3];
    if (tmp[4]) {
        _InterlockedExchangeAdd((volatile long*)((char*)tmp[4] + 4), 1);
    }
    r->p3 = tmp[4];
    r->p4 = tmp[5];
    r->p5 = 0;

    if (a) {
        if (_InterlockedExchangeAdd(&a->ref1, -1) != 1) {
            ((void (__thiscall*)(Obj*))((void**)a->vfptr)[1])(a);
            if (_InterlockedExchangeAdd(&a->ref2, -1) == 1) {
                ((void (__thiscall*)(Obj*))((void**)a->vfptr)[2])(a);
            }
        }
    }

    if (d) {
        if (_InterlockedExchangeAdd(&d->ref1, -1) == 1) {
            ((void (__thiscall*)(Obj*))((void**)d->vfptr)[1])(d);
            if (_InterlockedExchangeAdd(&d->ref2, -1) == 1) {
                ((void (__thiscall*)(Obj*))((void**)d->vfptr)[2])(d);
            }
        }
    }

    return r;
}

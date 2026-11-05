// from server: 44% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[4];
    void (__thiscall *vfn4)(Inner*);
    void (__thiscall *vfn8)(Inner*);
};

struct Obj {
    Inner* p;
    long* ref;
};

struct Holder {
    Obj* obj;
    long* ref;
};

extern "C" Holder* __cdecl sub_5e2b40(Holder* out);

struct S {
    Obj* f(Holder* arg);
};

Obj* S::f(Holder* arg)
{
    Holder tmp;
    tmp.obj = 0;
    sub_5e2b40(&tmp);
    Obj* src = tmp.obj;
    Obj* result = arg->obj;
    if (src) {
        result->p = (Inner*)((char*)src->p + 0x18);
    } else {
        result->p = 0;
    }
    result->ref = src->ref;
    if (result->ref) {
        _InterlockedExchangeAdd(result->ref + 1, 1);
    }
    Inner* si = (Inner*)tmp.ref;
    if (si) {
        if (_InterlockedExchangeAdd((long*)si + 1, -1) == 1) {
            si->vfn4(si);
            if (_InterlockedExchangeAdd((long*)si + 2, -1) == 1) {
                si->vfn8(si);
            }
        }
    }
    return result;
}

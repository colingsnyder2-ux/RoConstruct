// from server: 55% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void (__thiscall *vfn0)(void);
    void (__thiscall *vfn1)(void);
    void (__thiscall *vfn2)(void);
};

struct Obj {
    char pad0[4];
    volatile long ref1;
    volatile long ref2;
    char pad1[0x14];
    Inner inner;
};

struct Holder {
    char pad0[4];
    Obj* ptr;
};

extern "C" void __cdecl sub_6a2ce0(void*, void*);

void __cdecl sub_6a34c0(Holder* h)
{
    Obj* o;
    if (h != 0)
        o = (Obj*)((char*)h - 0x28);
    else
        o = 0;

    void* tmp;
    sub_6a2ce0(&o->inner, &tmp);

    Obj* p = *(Obj**)((char*)&tmp - 4);
    if (p != 0)
    {
        if (_InterlockedExchangeAdd(&p->ref1, -1) == 1)
        {
            p->inner.vfn1();
            if (_InterlockedExchangeAdd(&p->ref2, -1) == 1)
                p->inner.vfn2();
        }
    }
}

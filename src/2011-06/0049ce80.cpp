// from server: 59% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[0x18];
};

struct RefCounted {
    void** vptr;
    long refcount;
};

struct Holder {
    Inner* inner;
    RefCounted* ref;
};

extern "C" Holder* __cdecl sub_49CE00(Holder* out);

struct Result {
    void* p0;
    RefCounted* p4;
};

struct VTable {
    char pad0[4];
    void (__thiscall *dtor)(void*);
    void (__thiscall *dtor2)(void*);
};

struct Obj {
    VTable* vt;
    long ref1;
    long ref2;
};

Result* __stdcall func(Result* out, Obj* obj);

Result* __stdcall func(Result* out, Obj* obj)
{
    Holder h;
    h.inner = 0;
    sub_49CE00(&h);

    Inner* inner = h.inner;
    void* p0;
    if (inner != 0)
        p0 = (char*)inner + 0x18;
    else
        p0 = 0;

    out->p0 = p0;
    RefCounted* r = h.ref;
    out->p4 = r;
    if (r != 0)
        _InterlockedExchangeAdd(&r->refcount, 1);

    if (obj != 0)
    {
        if (_InterlockedExchangeAdd(&obj->ref1, -1) == 1)
        {
            VTable* vt = obj->vt;
            vt->dtor(obj);
            if (_InterlockedExchangeAdd(&obj->ref2, -1) == 1)
            {
                VTable* vt2 = obj->vt;
                vt2->dtor2(obj);
            }
        }
    }

    return out;
}

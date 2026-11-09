// from server: 44% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    long refCount;
};

struct Inner {
    char pad[0x188];
    int field188;
};

struct Obj {
    char pad0[0x34];
    Inner* ptr34;
    RefCounted* ptr38;
};

struct Arg {
    int a;
    int b;
};

struct Holder {
    void* p;
};

extern "C" void __stdcall sub_40D550(void*);
extern "C" void __stdcall sub_56BA60(void*, int, int);
extern "C" void __stdcall sub_57B4B0(int);
extern "C" void __stdcall sub_5595A0(void*);

struct VCWorkspace_CComObject {
    void method(int arg);
};

void VCWorkspace_CComObject::method(int arg)
{
    Obj* self = (Obj*)this;
    Inner* inner = self->ptr34;
    RefCounted* rc = self->ptr38;

    Arg local;
    local.a = (int)inner;
    local.b = (int)rc;
    if (rc) {
        _InterlockedExchangeAdd(&rc->refCount, 1);
    }

    sub_40D550(&local);

    int saved = arg;
    sub_56BA60(&local, saved, (int)inner);

    Inner* i2 = self->ptr34;
    int v;
    if (i2) {
        v = i2->field188;
    } else {
        v = 0;
    }
    sub_57B4B0(v);

    sub_5595A0(&local);
}

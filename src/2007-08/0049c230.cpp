// from server: 26% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    volatile long refCount1;
    volatile long refCount2;
};

struct Inner {
    int field0;
    int field4;
    int field8;
    int fieldC;
};

struct Holder {
    RefCounted* ptr;
    int field4;
};

struct Outer {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
};

extern "C" void __cdecl sub_417860(void*, int);
extern "C" void __cdecl sub_40CC20(void*, void*, int);
extern "C" void __cdecl sub_49C170(void*, void*);
extern "C" void __cdecl sub_49A440(void*, void*, int, int);
extern "C" void __cdecl sub_49A230(void*);

struct VClient {
    int method(int a1, int a2, int a3, int a4);
};

int VClient::method(int a1, int a2, int a3, int a4)
{
    Holder h;
    Outer o;
    int result;

    h.ptr = 0;
    h.field4 = a1;
    sub_417860(&h, a1);
    sub_40CC20(&h, &h, a1);
    sub_49C170(&o, &h);
    sub_49A440(&o, &o, a2, a4);
    sub_49A230(&o);

    if (h.ptr) {
        RefCounted* p = h.ptr;
        if (_InterlockedExchangeAdd(&p->refCount1, -1) == 1) {
            p->unknown1();
            if (_InterlockedExchangeAdd(&p->refCount2, -1) == 1) {
                p->unknown2();
            }
        }
    }

    result = a2;
    return result;
}

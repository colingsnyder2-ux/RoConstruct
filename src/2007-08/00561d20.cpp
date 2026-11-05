// from server: 28% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCountedBase {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    volatile long refCount;
    volatile long weakRefCount;
};

struct Obj104 {
    char pad[0x104];
    int* begin;
    int* end;
};

struct Inner {
    char pad[0x104];
    int* begin;
    int* end;
};

struct Outer {
    char pad[0xc];
    Inner* inner;
};

struct S {
    char pad[0xc];
    void* field_c;
    bool method();
};

extern "C" void* __cdecl sub_410d40(void*);
extern "C" void __cdecl sub_40fc90(void*, void*);
extern "C" void __cdecl sub_55f990(void*, void*);
extern "C" bool __cdecl sub_5d9dd0(void*, void*);

bool S::method()
{
    void* p = this->field_c;
    Inner* inner;
    if (p != 0) {
        inner = (Inner*)sub_410d40(p);
    } else {
        inner = 0;
    }

    int* begin = inner->begin;
    if (begin != 0) {
        return false;
    }
    int* end = inner->end;
    if (((end - begin) >> 3) != 2) {
        return false;
    }

    void* local1 = 0;
    void* local2 = 0;
    sub_40fc90(inner, &local2);
    sub_55f990(inner, &local1);

    bool result = sub_5d9dd0(local2, local1);

    if (local1 != 0) {
        RefCountedBase* r = (RefCountedBase*)local1;
        if (_InterlockedExchangeAdd(&r->refCount, -1) == 1) {
            r->unknown1();
            if (_InterlockedExchangeAdd(&r->weakRefCount, -1) == 1) {
                r->unknown2();
            }
        }
    }

    if (local2 != 0) {
        RefCountedBase* r = (RefCountedBase*)local2;
        if (_InterlockedExchangeAdd(&r->refCount, -1) == 1) {
            r->unknown1();
            if (_InterlockedExchangeAdd(&r->weakRefCount, -1) == 1) {
                r->unknown2();
            }
        }
    }

    return result;
}

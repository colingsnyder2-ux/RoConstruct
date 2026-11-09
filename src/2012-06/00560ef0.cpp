// from server: 14% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct type_info {
    bool operator==(const type_info&) const;
};

struct Inner {
    char pad0[0x10];
    type_info* ti;
};

struct Elem {
    char pad0[0x28];
    Inner* inner;
};

struct Iter {
    char pad0[0x24];
    Elem* elem;
};

struct RefCounted {
    virtual void f1();
    virtual void f2();
    virtual void f3();
    volatile long ref1;
    volatile long ref2;
};

struct SP {
    RefCounted* ptr;
};

struct Container {
    char pad0[4];
    Elem* end;
    char pad1[0x20];
    Elem* begin;
};

struct Result {
    void* p0;
    void* p1;
};

struct S {
    char pad0[4];
    Elem* end;
    char pad1[0x20];
    Elem* begin;
    Result get(Elem* e);
    Result find(Elem* e);
};

Result S::get(Elem* e) {
    Result r;
    r.p0 = 0;
    r.p1 = 0;
    return r;
}

Result S::find(Elem* e) {
    Result r;
    r.p0 = 0;
    r.p1 = 0;
    return r;
}

extern "C" void __stdcall sub_55e3a0(void*, void*);
extern "C" void __stdcall sub_6836f0(void*, void*, int);

Result __stdcall f(S* self, Elem* e) {
    Result r;
    r.p0 = 0;
    r.p1 = 0;
    return r;
}

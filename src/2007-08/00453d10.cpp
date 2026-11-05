// from server: 47% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Descriptor {
    void* vptr;
    void* name;
    void* attributes;
};

struct RefCounted {
    void* vptr;
    long refcount;
};

struct Inner {
    void* vptr;
    void* field4;
};

struct Outer {
    void* vptr;
    char pad[0x78];
    Inner* ptr7c;
    RefCounted* ptr80;
    void* ptr84;
};

extern "C" void __stdcall sub_40D550(void*);
extern "C" void __stdcall sub_5595A0(void*);
extern "C" void* __stdcall sub_77E6A8(void*);
extern "C" void __stdcall sub_77DDB8(void*, void*);

struct CValueItem {
    void construct(Outer* a, Outer* b);
};

void CValueItem::construct(Outer* a, Outer* b)
{
    Inner* p7c = a->ptr7c;
    RefCounted* p80 = a->ptr80;
    if (p80) {
        _InterlockedExchangeAdd(&p80->refcount, 1);
    }
    sub_40D550(&p7c);
    void* p84 = a->ptr84;
    void** vt = *(void***)p84;
    void (*fn)(void*) = (void (*)(void*))vt[0x44/4];
    fn(p84);
    void* r = sub_77E6A8((char*)p84 + 0xf0);
    sub_77DDB8(b, r);
    sub_5595A0(&p7c);
}

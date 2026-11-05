// from server: 20% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakRefCount;
    void Release();
};

struct String {
    char pad[0x10];
};

struct StringStream {
    char pad[0x60];
};

struct BoundFuncDesc {
    char pad[0x10];
    void* function;
    void BoundFuncDesc_ctor(void* function, const char* name, int security, int attributes);
};

extern "C" void __stdcall sub_493790(void*, const char*, int, int, void*);
extern "C" void __stdcall sub_4939a0(void*);
extern "C" void* __stdcall sub_52c940(const char*, int);
extern "C" void __stdcall sub_553ea0(void*, void*, int, void*);
extern "C" void __stdcall sub_566670(void*, void*);
extern "C" void __stdcall sub_56c0a0(void*, int, const char*, void*);
extern "C" void __stdcall sub_56c3b0(void*);
extern "C" void __stdcall sub_62fc62(void*);
extern "C" void* __stdcall sub_62fef6(unsigned int);
extern "C" void __stdcall sub_40f800(void*);
extern "C" void __stdcall sub_410250(void*, void*, void*, void*, void*);

extern "C" void __stdcall sub_77e5fc(void*);
extern "C" void __stdcall sub_77e678(void*);
extern "C" void __stdcall sub_77e6a4(void*);
extern "C" void __stdcall sub_77e6ac(void*);

void BoundFuncDesc::BoundFuncDesc_ctor(void* function, const char* name, int security, int attributes) {
    void* p = sub_62fef6(0x20);
    RefCounted* rc = 0;
    if (p) {
        rc = (RefCounted*)p;
        rc->vptr = 0;
        rc->refCount = 0;
        rc->weakRefCount = 0;
        rc->vptr = sub_52c940((const char*)0x79bc74, -1);
        rc->refCount = 0;
        rc->weakRefCount = 0;
    }
    this->function = rc;
    sub_493790(this, name, security, attributes, function);
    String s;
    sub_566670(&s, 0);
    sub_77e5fc(0);
    sub_40f800(&s);
    StringStream ss;
    sub_410250(&ss, 0, 0, 0, 0);
    sub_62fc62(0);
    sub_77e6a4(0);
    sub_553ea0(0, 0, 0, 0);
    sub_56c3b0(0);
    sub_56c0a0(0, 1, (const char*)0x79bc58, 0);
    if (rc) {
        if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
            rc->vptr = 0;
            rc->Release();
        }
        if (_InterlockedExchangeAdd(&rc->weakRefCount, -1) == 1) {
            rc->vptr = 0;
            rc->Release();
        }
    }
    sub_77e6ac(0);
    sub_77e678(0);
    sub_4939a0(0);
}

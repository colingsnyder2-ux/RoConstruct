// from server: 70% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sub_642ee0();
extern "C" void* __cdecl sub_7f3860(unsigned int);

struct Inner {
    void* vptr;
    volatile long refcount;
};

struct Holder {
    void* field0;
    Inner* field4;
};

struct VLiveThreadRef {
    void* field0;
    Holder* field4;
    VLiveThreadRef(Holder* h);
};

VLiveThreadRef::VLiveThreadRef(Holder* h) {
    ++*(volatile long*)0xb8ffe0;
    field0 = (void*)sub_642ee0();
    Inner* p = (Inner*)sub_7f3860(0xc);
    if (p) {
        p->vptr = (void*)0x9ba1d4;
        *(void**)((char*)p + 4) = *(void**)h;
        void* r = *(void**)((char*)h + 4);
        *(void**)((char*)p + 8) = r;
        if (r) {
            _InterlockedExchangeAdd((volatile long*)((char*)r + 4), 1);
        }
        field4 = (Holder*)p;
    } else {
        field4 = 0;
    }
}

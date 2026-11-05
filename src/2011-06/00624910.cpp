// from server: 25% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall SetEvent(void*);

extern "C" void __cdecl sub_40A2B0();
extern "C" void __cdecl sub_40DDC0(void*);
extern "C" void __cdecl sub_411500();
extern "C" void __cdecl sub_6B6F40(void*);
extern "C" void __cdecl sub_80B15D(void*);

struct RefCounted {
    long refcount;
    char pad[8];
    void Release();
};

struct Holder {
    RefCounted* ptr;
    char flag;
};

struct VInstance {
    void* field0;
    bool Method(Holder* h);
};

void RefCounted::Release() {
    if (_InterlockedExchangeAdd(&refcount, 0x80000000) >= 0x40000000)
        return;
    if (_InterlockedExchangeAdd(&refcount, 0) <= 0x80000000)
        return;
    if (_InterlockedExchangeAdd(&refcount, 0) & 0x40000000)
        return;
    sub_40A2B0();
    SetEvent(*(void**)0xa40374);
}

bool VInstance::Method(Holder* h) {
    if (*(void**)0xccbf50 == 0) {
        *(void**)0xccbf50 = (void*)1;
        *(void**)0xccbf48 = 0;
        *(void**)0xccbf4c = 0;
        sub_80B15D((void*)0xa39ad0);
    }
    Holder local;
    local.ptr = (RefCounted*)0xccbf48;
    local.flag = 0;
    sub_411500();
    void* p = field0;
    if (p == 0)
        sub_6B6F40(0);
    else
        sub_6B6F40((char*)p + 0xc);
    if (field0 == 0) {
        if (local.flag)
            local.ptr->Release();
        return false;
    } else {
        if (local.flag)
            local.ptr->Release();
        return true;
    }
}

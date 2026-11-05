// from server: 18% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall SetEvent(void*);
extern "C" void __cdecl free(void*);

extern "C" void __cdecl func_004015a0();
extern "C" void* __cdecl func_0040b9c0();
extern "C" void __cdecl func_0040c750(void*);
extern "C" void __cdecl func_00413890();
extern "C" void __cdecl func_006d31d0(void*);
extern "C" void __cdecl func_009831f5();

struct RefCounted {
    long refcount;
    void* vtable;
    void Release();
};

struct Job {
    void* field0;
    bool Execute(void* arg);
};

void RefCounted::Release()
{
    if (_InterlockedExchangeAdd(&refcount, -1) == 1) {
        void** vt = (void**)vtable;
        void (*fn)(void*) = (void (*)(void*))vt[0];
        fn(0);
        if (_InterlockedExchangeAdd(&refcount, -1) == 1) {
            free(this);
        }
    }
}

bool Job::Execute(void* arg)
{
    void* local = field0;
    if (local != 0) {
        func_0040c750((char*)local + 5);
    }
    func_004015a0();
    if ((*(unsigned char*)0xe25de4 & 1) == 0) {
        *(unsigned int*)0xe25de4 |= 1;
        *(unsigned int*)0xe25ddc = 0;
        *(unsigned int*)0xe25de0 = 0;
        func_009831f5();
    }
    func_00413890();
    if (field0 != 0) {
        func_006d31d0((char*)field0 + 0xc);
    } else {
        func_006d31d0(this);
    }
    if (field0 == 0) {
        return false;
    }
    return true;
}

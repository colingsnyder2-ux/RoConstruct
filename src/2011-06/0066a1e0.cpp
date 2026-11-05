// from server: 39% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl malloc(unsigned int);

struct RefCounted {
    short refcount;
    short pad;
    void* vptr;
};

struct Obj {
    char pad0[4];
    void* field4;
};

extern void func_006686a0();
extern void func_00669b20();

struct HumanoidController {
    void func_0066a1e0(void* a, void** out);
};

void HumanoidController::func_0066a1e0(void* a, void** out)
{
    RefCounted* rc = (RefCounted*)malloc(0x3c);
    if (rc) {
        rc->refcount = 0;
        rc->pad = 1;
    }
    Obj* obj = (Obj*)((char*)rc + 4);
    if (obj) {
        func_006686a0();
        *(void**)obj = (void*)0xa9c2c8;
        *(void**)((char*)obj + 8) = (void*)0xa9c2c0;
    } else {
        obj = 0;
    }
    func_00669b20();
    *out = obj;
    if (obj) {
        volatile short* p = (volatile short*)((char*)obj - 2);
        _InterlockedExchangeAdd((volatile long*)p, 1);
    }
}

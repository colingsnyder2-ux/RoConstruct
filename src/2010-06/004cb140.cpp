// from server: 33% by tester
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl func_005a9e00();
extern "C" void __cdecl func_005a5510();
extern "C" void __cdecl func_004a6fa0();

struct RefCounted
{
    void* vptr;
    volatile long refCount;
};

struct ArgHolder
{
    void* ptr;
    RefCounted* ref;
};

struct Target
{
    char pad[0x38];
    void* field38;
    int field3c;
    void invoke(void* arg, ArgHolder* out);
};

void Target::invoke(void* arg, ArgHolder* out)
{
    ArgHolder local;
    func_005a9e00();
    local.ptr = 0;
    local.ref = 0;
    if (local.ref)
    {
        _InterlockedExchangeAdd(&local.ref->refCount, 1);
    }
    void* fn = field38;
    int off = field3c;
    char* base = (char*)arg + off;
    void* result = ((void* (__cdecl*)(void*, ArgHolder*))fn)(base, &local);
    _InterlockedExchangeAdd((volatile long*)0xc18600, 1);
    local.ptr = 0;
    func_005a5510();
    out->ptr = result;
    func_004a6fa0();
    if (local.ref)
    {
        if (_InterlockedExchangeAdd(&local.ref->refCount, -1) == 1)
        {
            ((void (__cdecl*)(RefCounted*))local.ref->vptr)(local.ref);
            if (_InterlockedExchangeAdd(&local.ref->refCount, -1) == 1)
            {
                ((void (__cdecl*)(RefCounted*))local.ref->vptr)(local.ref);
            }
        }
    }
}

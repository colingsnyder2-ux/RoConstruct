// from server: 31% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakRefCount;
};

struct S_func_004904c0 {
    int f(void* a, void* b, void* c, void* d);
};

extern "C" void __cdecl func_00417860(void*, void*);
extern "C" void __cdecl func_0040cc20(void*, void*, void*);
extern "C" void __cdecl func_00490190(void*, void*);
extern "C" void __cdecl func_0048a410(void*, void*, void*, void*);
extern "C" void __cdecl func_0049a230(void*);

int S_func_004904c0::f(void* a, void* b, void* c, void* d)
{
    char buf[8];
    void* local1;
    void* local2;
    RefCounted* rc;
    void* local3;
    void* local4;
    void* local5;
    int result;

    local1 = 0;
    local2 = a;
    func_00417860(&local2, a);
    func_0040cc20(&local2, a, a);
    func_00490190(&local3, &local2);
    func_0048a410(b, &local3, c, d);
    func_0049a230(&local2);

    rc = (RefCounted*)local2;
    if (rc != 0) {
        if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))rc->vptr)(rc);
            if (_InterlockedExchangeAdd(&rc->weakRefCount, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))rc->vptr)(rc);
            }
        }
    }

    result = (int)c;
    return result;
}

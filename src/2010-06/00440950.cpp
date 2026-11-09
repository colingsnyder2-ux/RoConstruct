// from server: 28% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refcount;
    volatile long weakrefcount;
};

struct ScriptItem {
    void method(int, int, int);
};

extern "C" void* __cdecl func_007a79a0(unsigned int);
extern "C" void* __cdecl func_00436950(void*, int, int);
extern "C" void __cdecl func_0041ddf0(void*, void*);
extern "C" void __cdecl func_004545b0(void*, void*, void*);
extern "C" void __cdecl func_0041fbe0(void*);
extern "C" void __cdecl func_0064d9a0(void*, void*);
extern "C" void* __cdecl func_0041b220(void*);
extern "C" void __cdecl func_0041afe0(void*);

typedef void (__stdcall *FnPtr)();

void ScriptItem::method(int a, int b, int c)
{
    void* p = func_007a79a0(0x48);
    RefCounted* obj = 0;
    if (p != 0) {
        obj = (RefCounted*)func_00436950(p, b, a);
    }
    RefCounted* local = obj;
    func_0041ddf0(&local, obj);
    func_004545b0(&local, obj, obj);
    func_0041fbe0(this);
    func_0064d9a0(this, &local);
    FnPtr fn = *(FnPtr*)0x9ea380;
    fn();
    RefCounted* tmp = local;
    func_0041b220(&local);
    FnPtr fn2 = *(FnPtr*)0x9ea380;
    fn2();
    (void)c;
}

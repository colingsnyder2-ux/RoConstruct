// from server: 41% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)



struct RefCounted {
    long refCount;
};

struct Listener {
    void process(RefCounted* a, RefCounted* b, int c, int d, int e);
    void G1_func_0077e69c();
};

void Listener::process(RefCounted* a, RefCounted* b, int c, int d, int e)
{
    char buf[0x30];
    RefCounted* self = a ? (RefCounted*)((char*)a - 0xe8) : 0;
    G1_func_0077e69c();
    int* stack_ptr = (int*)(buf + 0x10);
    stack_ptr[0x1c] = c;
    stack_ptr[0x20] = d;
    if (d != 0) {
        _InterlockedExchangeAdd((volatile long*)(d + 4), 1);
    }
    stack_ptr[0x24] = e;
    stack_ptr[0x28] = e;
    if (e != 0) {
        _InterlockedExchangeAdd((volatile long*)(e + 4), 1);
    }
    void** vtbl = *(void***)b;
    void* fn = vtbl[0];
    ((void (__thiscall*)(RefCounted*, RefCounted*))fn)(b, self);
}

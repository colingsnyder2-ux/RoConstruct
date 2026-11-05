// from server: 35% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall G1_func_0077e69c();

struct RefCounted {
    long refCount;
};

struct Listener {
    void construct(RefCounted* a, RefCounted* b, int c, int d, int e, int f, int g);
};

void Listener::construct(RefCounted* a, RefCounted* b, int c, int d, int e, int f, int g)
{
    char buf[0x2c];
    RefCounted* self = this ? (RefCounted*)((char*)this - 0xe8) : 0;
    G1_func_0077e69c();
    *(int*)(buf + 0x1c) = c;
    *(int*)(buf + 0x20) = d;
    if (d != 0) {
        _InterlockedExchangeAdd((volatile long*)(d + 4), 1);
    }
    *(int*)(buf + 0x24) = e;
    *(int*)(buf + 0x28) = f;
    if (f != 0) {
        _InterlockedExchangeAdd((volatile long*)(f + 4), 1);
    }
    void** vtbl = *(void***)b;
    void* fn = vtbl[0];
    ((void (__thiscall*)(void*, RefCounted*))fn)(b, self);
}

// from server: 15% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Ref {
    void* ptr;
    void (*release)(void*);
};

struct Inner {
    void (__stdcall *vtbl)(int);
    char pad[0x1c];
};

struct Outer {
    char pad0[0xc];
    Inner* inner;
    void func(int a, void* b, Ref* c);
};

void __cdecl sub_401de0(void*);

void Outer::func(int a, void* b, Ref* c)
{
    Ref local;
    local.ptr = b;
    local.release = c->release;
    if (local.release)
        _InterlockedExchangeAdd((volatile long*)((char*)local.release + 4), 1);
    void (__stdcall *f)(int) = *(void (__stdcall **)(int))((char*)this->inner + 0x20);
    f(a);
    if (local.release)
        sub_401de0(local.release);
}

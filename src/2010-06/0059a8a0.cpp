// from server: 53% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void** vptr;
    char pad[4];
    volatile long ref1;
    volatile long ref2;
    void Release();
};

void RefCounted::Release() {
    if (_InterlockedExchangeAdd(&ref1, -1) == 1) {
        ((void(__thiscall*)(RefCounted*))vptr[1])(this);
        if (_InterlockedExchangeAdd(&ref2, -1) == 1) {
            ((void(__thiscall*)(RefCounted*))vptr[2])(this);
        }
    }
}

struct Args {
    void (__stdcall* fn)(int, int, int);
    int a;
    int b;
    int c;
};

void __stdcall func_0059a8a0(Args* args, RefCounted* p1, RefCounted* p2) {
    args->fn(args->a, args->b + args->c, args->c);
    if (p1) p1->Release();
    if (p2) p2->Release();
}

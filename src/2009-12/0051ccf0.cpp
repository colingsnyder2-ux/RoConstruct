// from server: 20% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl func_00642ee0();
extern "C" void* __cdecl func_006462b0();
extern "C" void __cdecl func_004f90e0(void*, int);

struct S {
    char pad[0x38];
    int (__thiscall *fn38)(void*, void*);
    int field3c;
    int method(int, int, int);
};

int S::method(int a, int b, int c)
{
    void* p = func_006462b0();
    int v = *(int*)p;
    int r;
    r = fn38((char*)this + 0x3c + a, &v);
    _InterlockedExchangeAdd((volatile long*)0xb8ffe0, 1);
    void* q = func_00642ee0();
    *(void**)b = q;
    func_004f90e0((char*)b + 4, r);
    return r;
}

// from server: 43% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_401610();
extern "C" void __cdecl sub_764080(void*, int, void*);

struct S {
    void f();
};

void S::f() {
    sub_401610();
    _InterlockedExchangeAdd((volatile long*)0xccdb1c, -1);
    sub_764080(*(void**)0xc8eff8, 1, *(void**)((char*)0 + 12));
}

// from server: 58% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_401610();
extern "C" int __cdecl sub_764080(int, int, int);

struct S {
    int f();
};

int S::f() {
    sub_401610();
    _InterlockedExchangeAdd((volatile long*)0xccdb1c, -1);
    sub_764080(*(int*)0xc8efc0, 1, *(int*)((char*)this + 4));
    return 0;
}

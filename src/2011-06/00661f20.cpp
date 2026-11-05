// from server: 76% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_401610(int, int);
extern "C" int __cdecl sub_764080(int, int, int);

struct S {
    int f(int);
};

int S::f(int a) {
    sub_401610(0x661100, 0xccdb18);
    _InterlockedExchangeAdd((volatile long*)0xccdb1c, -1);
    sub_764080(*(int*)0xc8efe8, 1, a);
    return 0;
}

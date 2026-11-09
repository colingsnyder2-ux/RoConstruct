// from server: 49% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_401610(int, int);
extern "C" void __cdecl sub_764080(int, int);

int __cdecl sub_661ee0(int a)
{
    sub_401610(0xccdb18, 0x661100);
    _InterlockedExchangeAdd((volatile long*)0xccdb1c, -1);
    sub_764080(1, a);
    return 0;
}

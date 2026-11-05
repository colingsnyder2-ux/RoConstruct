// from server: 69% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    void f();
};

void S::f()
{
    long* p = *(long**)0x00b7b9b4;
    if (p != 0)
    {
        long* q = p + 2;
        if (_InterlockedExchangeAdd(q, -1) == 1)
        {
            void (**vtable)() = *(void (***)())p;
            vtable[2]();
        }
    }
}

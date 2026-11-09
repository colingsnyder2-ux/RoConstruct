// from server: 76% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    void f();
};

extern "C" void __cdecl helper(void*);

void S::f()
{
    long old = _InterlockedExchangeAdd((volatile long*)((char*)*(void**)this + 8), -1);
    void* p = *(void**)this;
    if (p != 0)
        helper(p);
}

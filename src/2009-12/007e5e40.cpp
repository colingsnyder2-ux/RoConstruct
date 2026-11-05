// from server: 100% by atomic.potato
extern "C" long __declspec(dllimport) __stdcall InterlockedIncrement(volatile long *);

struct S
{
    void f();
};

void S::f()
{
    InterlockedIncrement((volatile long *)((char *)this + 0x198));
}

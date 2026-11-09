// from server: 100% by atomic.potato
extern "C" long __declspec(dllimport) __stdcall InterlockedDecrement(long *);

struct S
{
    void f();
};

void S::f()
{
    InterlockedDecrement((long *)((char *)this + 0x1a4));
}

// from server: 25% by atomic.potato
extern "C" long __stdcall InterlockedDecrement(long volatile *);

struct S
{
    int f();
};

int S::f()
{
    long volatile *p = (long volatile *)((char *)this + 8);
    InterlockedDecrement(p);
    return 0;
}

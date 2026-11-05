// from server: 40% by atomic.potato
extern "C" long __stdcall InterlockedIncrement(long *);

struct S
{
    int f(int);
};

int S::f(int)
{
    long *p = (long *)((char *)this + 8);
    InterlockedIncrement((long *)((char *)p + 0x804));
    return 0;
}

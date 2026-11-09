// from server: 42% by atomic.potato
extern "C" long __stdcall InterlockedDecrement(volatile long *);

struct S
{
    int f(int);
};

int S::f(int value)
{
    long *p = (long *)((char *)this + 8);
    InterlockedDecrement((volatile long *)((char *)this + 0x80c));
    return value;
}

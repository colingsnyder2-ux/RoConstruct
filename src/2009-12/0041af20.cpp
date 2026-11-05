// from server: 93% by atomic.potato
extern "C" long __stdcall InterlockedDecrement(long *);

struct S
{
    int value;
    S *f(int);
};

S *S::f(int flag)
{
    value = 0x9a2cc4;
    InterlockedDecrement((long *)0xb7a224);
    if (flag & 1)
        delete this;
    return this;
}

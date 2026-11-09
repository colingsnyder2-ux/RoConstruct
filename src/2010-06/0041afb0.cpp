// from server: 93% by atomic.potato
extern "C" long __stdcall InterlockedDecrement(long *);

struct T
{
    int *value;
    void *f(unsigned char);
};

void *T::f(unsigned char flag)
{
    value = (int *)0x00a0399c;
    InterlockedDecrement((long *)0x00c007ac);
    if (flag & 1)
        delete this;
    return (void *)this;
}

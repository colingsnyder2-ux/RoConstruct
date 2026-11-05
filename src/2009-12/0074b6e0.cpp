// from server: 38% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    volatile int *p = (volatile int *)0x5f0c244c;
    --*p;
}

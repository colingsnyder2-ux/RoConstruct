// from server: 48% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    volatile int *p = (volatile int *)((char *)this + 0x5f0c244c);
    --*p;
}

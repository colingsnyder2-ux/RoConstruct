// from server: 48% by atomic.potato
struct S
{
    void f(int, int, int);
};

void S::f(int, int, int)
{
    volatile int *p = (volatile int *)0x4d8b04c4;
    ++*p;
}

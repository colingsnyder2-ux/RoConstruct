// from server: 100% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int *)this = 0xa360d4;
    *((int *)this + 1) = 0xa360cc;
    *((int *)this + 6) = 0xa360c0;
    *((int *)this + 7) = 0xa360b4;
    extern void g();
    g();
}

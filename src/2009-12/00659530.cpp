// from server: 100% by atomic.potato
struct S
{
    S *f();
};

S *g();

S *S::f()
{
    *(int *)this = 0x9cd7ac;
    *(int *)((char *)this + 4) = 0x9cd7a4;
    *(int *)((char *)this + 0x18) = 0x9cd798;
    *(int *)((char *)this + 0x1c) = 0x9cd790;
    return g();
}

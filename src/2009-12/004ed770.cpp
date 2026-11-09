// from server: 15% by atomic.potato
struct S
{
    int *f();
};

int *S::f()
{
    int *p = (int *)((char *)this + 16);
    return p;
}

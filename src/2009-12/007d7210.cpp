// from server: 80% by atomic.potato
struct S;

extern "C" void G1_func_007d79a0(S *, void *, void *);

struct S
{
    int *f(void *, void *);
};

int *S::f(void *a, void *b)
{
    G1_func_007d79a0(this, a, b);
    *(int *)this = 0x9ef5a8;
    *((int *)this + 1) = 0x9ef5a0;
    return (int *)this;
}

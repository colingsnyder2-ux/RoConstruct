// from server: 58% by atomic.potato
extern "C" void sub_95e600(void *, void *);

struct S
{
    int *f(void *);
};

int *S::f(void *arg)
{
    sub_95e600(this, arg);
    *(int *)this = (int)0xbf2120;
    *((int *)this + 1) = (int)0xbf2114;
    return (int *)this;
}

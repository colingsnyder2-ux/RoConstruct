// from server: 47% by atomic.potato
extern "C" int sub_005bea60(void *, void *);

struct S
{
    int f(void *);
};

int S::f(void *arg)
{
    void *p = *(void **)((char *)this + 0x1c);
    void *q = (void *)((char *)arg);
    void **r = *(void ***)((char *)p);
    r = (void **)((char *)r + 8);
    sub_005bea60(this, q);
    return (int)*r;
}

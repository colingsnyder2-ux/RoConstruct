// from server: 75% by atomic.potato
struct S
{
    int f(void *);
};

struct T
{
    void g(void *);
};

int S::f(void *p)
{
    ((T *)((char *)this + 0x98))->g(p);
    return (int)p;
}

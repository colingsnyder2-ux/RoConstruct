// from server: 100% by atomic.potato
struct S
{
    void f(void *, void *, int);
    void g(void *);
};

struct RakPeer
{
    void f(void *);
};

void RakPeer::f(void *p)
{
    S *s = (S *)this;
    s->f(p, (void *)0x20, 1);
    *(unsigned int *)p = ~*(unsigned int *)p;
    s->g((char *)p + 4);
}

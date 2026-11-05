// from server: 45% by atomic.potato
struct S
{
    int reserved;
    void (*callback)(S *, int);
    void f();
};

void S::f()
{
    S *p = *(S **)((char *)this + 4);
    if (p != 0)
        p->callback(p, 1);
}

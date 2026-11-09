// from server: 87% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    S *p = (S *)this;
    if (p)
        ((void (__thiscall *)(S *, int))(*(int **)p)[16])(p, 1);
}

// from server: 84% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    struct V
    {
        void (__thiscall *g)(V *, int);
    };

    S *p = *(S **)((char *)this + 12);
    if (p)
        ((V *)*(int *)p)->g((V *)p, 1);
}

// from server: 100% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    int p = *(int *)this;
    if (p)
    {
        int v = *(int *)p;
        void (__thiscall *g)(int *, int) = *(void (__thiscall **)(int *, int))((char *)v + 0x3c);
        g((int *)p, 1);
    }
}

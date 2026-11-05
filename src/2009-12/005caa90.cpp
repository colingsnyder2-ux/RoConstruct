// from server: 62% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    int **p = *(int ***)this;
    if (p)
        ((void (__thiscall *)(int **, int))p[4])(p, 1);
}

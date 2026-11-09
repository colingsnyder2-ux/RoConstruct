// from server: 41% by atomic.potato
struct S
{
    int *p;
    void f();
};

void S::f()
{
    int *p = this->p;
    if (p)
    {
        void (__thiscall *fn)(int *, int) =
            *(void (__thiscall **)(int *, int))(*(int *)p + *(int *)(*(int *)p + 4));
        fn(p, 1);
    }
}

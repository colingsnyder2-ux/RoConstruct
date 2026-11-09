// from server: 94% by atomic.potato
struct S
{
    int f(int);
    int (__thiscall *vtable[2])(int);
};

int S::f(int p)
{
    int *q = (int *)p;
    S *x = this;
    if (q != 0)
    {
        q = (int *)((char *)q - 28);
        if (q != 0)
        {
            int *y = (int *)((char *)q + 512);
            return x->vtable[1]((int)y);
        }
    }
    return x->vtable[1](0);
}

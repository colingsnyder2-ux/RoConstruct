// from server: 68% by atomic.potato
struct S
{
    int f(void *);
};

int S::f(void *p)
{
    int *q = (int *)p;
    int *r;
    if (q != 0)
    {
        q = (int *)((char *)q - 28);
        if (q != 0)
        {
            r = (int *)((char *)q + 152);
            return ((int (__thiscall *)(int *, int *))(*(int **)((char *)this + 4)))(r, q);
        }
    }
    return ((int (__thiscall *)(int *, int *))(*(int **)((char *)this + 4)))((int *)this, 0);
}

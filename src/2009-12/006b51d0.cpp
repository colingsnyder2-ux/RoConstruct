// from server: 47% by atomic.potato
struct S
{
    int f(void *);
};

int S::f(void *p)
{
    return ((int (__thiscall *)(void *, int))(*(int *)p))(
        (void *)((char *)p + *(int *)((char *)p + 4) + *(int *)((char *)p + 8)),
        *(int *)((char *)p + 8));
}

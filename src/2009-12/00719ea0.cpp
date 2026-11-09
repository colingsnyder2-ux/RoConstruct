// from server: 84% by atomic.potato
struct S
{
    void f(void *);
    int *vptr;
    int pad[53];
    int count;
};

void S::f(void *arg)
{
    int *p = *(int **)((char *)this + 0xd8);
    ((void (__thiscall *)(void *, void *))(*(int **)*p + 3))(p, arg);
    ++*(int *)((char *)this + 0x98);
}

// from server: 73% by atomic.potato
struct S
{
    int f(void *);
};

int S::f(void *p)
{
    char *a;
    if (p)
        a = (char *)p - 0x1c;
    else
        a = 0;

    char *b = *(char **)(a + 0xb4);
    int i = *(int *)((char *)this + 0x10);
    char *c = *(char **)((char *)this + 8);
    void *d = (char *)b + i + *(int *)((char *)this + 0xc) + (int)a + 0xb4;

    return ((int (__thiscall *)(void *))c)(d);
}

// from server: 75% by atomic.potato
struct S
{
    int f(void *);
};

int S::f(void *p)
{
    unsigned char *a;
    if (p)
        a = (unsigned char *)p - 28;
    else
        a = 0;
    int *b = *(int **)(a + 324);
    int i = *(int *)((unsigned char *)this + 16);
    int *c = (int *)((unsigned char *)b + i);
    int d = *c + *(int *)((unsigned char *)this + 12);
    typedef int (__thiscall *F)(void *);
    F fn = *(F *)((unsigned char *)this + 8);
    return fn((void *)(a + 324 + d));
}

// from server: 63% by atomic.potato
struct S
{
    int pad0;
    int pad1;
    int (*call)(void *, void *);
    int offset;

    int f(void *p);
};

int S::f(void *p)
{
    char *base;
    int index;
    int value;

    base = (char *)p;
    if (base != 0)
        base -= 0x1c;
    else
        base = 0;

    index = *(int *)((char *)this + 0x10);
    value = *(int *)(*(int *)(base + 0x148) + index);
    value += *(int *)((char *)this + 0x0c);
    return ((int (__cdecl *)(void *, void *))*(int *)((char *)this + 8))(
        (void *)((char *)this + value + (int)base + 0x148), 0);
}

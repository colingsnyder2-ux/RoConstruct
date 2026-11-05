// from server: 67% by atomic.potato
struct S {
    int a;
    int b;
    int c;
    int f(void *, int);
};

int S::f(void *p, int q)
{
    char *x;
    int y;
    int z;

    x = (char *)p;
    if (x)
        x -= 0x1c;
    else
        x = 0;

    y = *(int *)((char *)this + 0x30);
    z = *(int *)((char *)this + 0x34);
    ((void (__thiscall *)(int, int))y)(
        (int)(x + 0x84 + z + *(int *)(((char *)this + 0x38) + *(int *)(x + 0x84))),
        q
    );
    return 0;
}

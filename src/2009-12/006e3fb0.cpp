// from server: 60% by atomic.potato
struct S {
    char pad[0x18];
    int (__stdcall *fn)(int, int);
    char pad2[0x20 - 0x18 - 4];
    int idx;
    int f(int a, int b);
};

int S::f(int a, int b)
{
    int *p;
    if (a != 0)
        p = (int *)(a - 0x1c);
    else
        p = 0;
    unsigned char c = *(unsigned char *)b;
    int *q = (int *)((char *)p + 0x148);
    int v = *(int *)((char *)q + idx);
    v += *(int *)((char *)this + 0x1c);
    int (__stdcall *fn)(int, int) = *(int (__stdcall **)(int, int))((char *)this + 0x18);
    return fn(v, (int)c);
}

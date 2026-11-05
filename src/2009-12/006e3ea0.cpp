// from server: 51% by atomic.potato
struct S {
    char pad[0x18];
    int (__cdecl *fn)(float, int);
    int field1c;
    int field20;
    void method(int, int);
};

void S::method(int a, int b)
{
    int *p = (int *)a;
    if (p)
        p = (int *)((char *)p - 0x1c);
    else
        p = 0;
    int idx = field20;
    int *q = (int *)b;
    float f = *(float *)q;
    int *r = (int *)((char *)p + 0x148);
    int v = *(int *)((char *)r + idx);
    v += field1c;
    int (__cdecl *fp)(float, int) = fn;
    fp(f, (int)((char *)p + 0x148 + v));
}

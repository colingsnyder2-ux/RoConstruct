// from server: 54% by atomic.potato
struct S
{
    int field8;
    int fieldC;
    int field10;
    int field138;
    int f(void *);
};

int S::f(void *p)
{
    int *v = p ? (int *)((char *)p - 0x1c) : 0;
    int *base = *(int **)((char *)0 + 0x138);
    int index = field10;
    int *target = (int *)((char *)base + index * 4);
    int *obj = (int *)((char *)target + fieldC + (int)v + 0x138);
    return ((int (__thiscall *)(int *))field8)(obj);
}

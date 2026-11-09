// from server: 59% by atomic.potato
struct S
{
    int f();
    int padding[11];
    int field2c;
};

int S::f()
{
    int p = field2c;
    if (!p)
        return 0;

    int q = *(int *)(p + 0x54);
    int r = *(int *)q;
    if (!r)
        return 0;

    int *v = (int *)(r + 0xf0);
    return *v;
}

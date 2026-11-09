// from server: 56% by atomic.potato
struct S
{
};

int * __cdecl f(int *p)
{
    int *q;
    if (p)
        q = (int *)((char *)p + 0x70);
    else
        q = 0;
    int *r = (int *)q[0];
    int *a = r;
    while ((int *)a[0] != q)
        a = (int *)a[0];
    r[0] = (int)a;
    return r;
}

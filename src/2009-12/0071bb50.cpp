// from server: 47% by atomic.potato
extern "C" int __cdecl Geometry(void *);

int f(void *p)
{
    int *q;
    if (!p)
        return 0;
    q = (int *)Geometry(p);
    if (!q)
        return 0;
    return q[23] ? q[23] : 0;
}

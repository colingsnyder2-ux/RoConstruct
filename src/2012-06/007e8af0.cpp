// from server: 39% by atomic.potato
struct S
{
    int __cdecl f(int *, int, int, int, int, int);
};

int S::f(int *p, int a, int b, int c, int d, int e)
{
    struct T
    {
        int x;
        int y;
        int z;
        int w;
    };

    T t;
    t.x = e;
    t.y = b;
    t.z = c;
    t.w = d;
    return p[1] + a ? ((int (__cdecl *)(int, T *))p[0])(p[1] + a, &t) : 0;
}

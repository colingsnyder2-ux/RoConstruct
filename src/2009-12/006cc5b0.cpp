// from server: 100% by atomic.potato
struct S
{
};

int * __cdecl f(int *p)
{
    if (p != 0 && p[62] != 0)
        return (int *)((char *)p[62] - 164);
    return 0;
}

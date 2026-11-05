// from server: 80% by atomic.potato
struct S
{
    S(int, int);
    int value;
};

S::S(int a, int b)
{
    value = 0;
}

extern "C" S * __stdcall create_S(S *, int, int);

S * __stdcall create_S(S *p, int a, int b)
{
    create_S(p, a, b);
    *(int *)p = 0x00bfdc10;
    *(int *)((char *)p + 0xd0) = 0;
    return p;
}

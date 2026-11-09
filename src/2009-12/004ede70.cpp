// from server: 32% by atomic.potato
struct S
{
};

int __cdecl f(int *p, int a, int b)
{
    int x = 0;
    p[0] = a;
    p[1] = b;
    x |= 1;
    return (int)p;
}

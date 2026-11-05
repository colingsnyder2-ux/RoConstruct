// from server: 32% by atomic.potato
struct S
{
};

int __cdecl f(int* a, int b, int c)
{
    int v = 0;
    a[0] = b;
    a[1] = c;
    v |= 1;
    return (int)a;
}

// from server: 61% by atomic.potato
struct S
{
    void __cdecl f(int *a, int b, int c, int d, int e);
};

void S::f(int *a, int b, int c, int d, int e)
{
    a[0] = b;
    a[1] = c;
    a[2] = e;
}

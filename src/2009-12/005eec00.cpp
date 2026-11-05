// from server: 100% by atomic.potato
struct S
{
};

void __cdecl f(int *a, int b, int c, int value)
{
    ((int *)a[1])[a[2] * c + b] = value;
}

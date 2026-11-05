// from server: 93% by atomic.potato
struct S
{
    int __cdecl f(int* a, unsigned int n);
};

int __cdecl S::f(int* a, unsigned int n)
{
    while (n != 0)
    {
        --n;
        if (a[n] != 0)
            return n + 1;
    }
    return 0;
}

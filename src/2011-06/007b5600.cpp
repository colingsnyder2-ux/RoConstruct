// from server: 33% by atomic.potato
struct S
{
    int __cdecl f(int *first, int *last, int *out);
};

int S::f(int *first, int *last, int *out)
{
    while (first != last)
    {
        out[-4] = first[-4];
        out[-3] = first[-3];
        out[-2] = first[-2];
        out[-1] = first[-1];
        first -= 4;
        out -= 4;
    }
    return 0;
}

// from server: 81% by atomic.potato
struct S
{
    static int f(const S *, const S *);
};

int S::f(const S *a, const S *b)
{
    return *(const double *)((const char *)b + 0xc0) <
           *(const double *)((const char *)a + 0xc0);
}

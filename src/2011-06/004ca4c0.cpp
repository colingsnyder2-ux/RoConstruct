// from server: 73% by atomic.potato
typedef int (__cdecl *CompareString)(const void *, const void *);

extern "C" CompareString g_compare;

struct S
{
    int *p;
    int *f(const char *, const char *);
};

int *S::f(const char *a, const char *b)
{
    int *p = ((S *)a)->p;
    while (p != 0)
    {
        if (g_compare(b, p - 7))
            break;
        p = (int *)*p;
    }
    return p;
}

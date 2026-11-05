// from server: 91% by atomic.potato
typedef int bool32;

extern "C" bool32 __cdecl string_equal(const void *, const void *);

struct S
{
};

bool32 __cdecl f(const void *a, const void *b)
{
    const void *x = *(const void **)((const char *)b + 4);
    const void *y = *(const void **)((const char *)a + 4);
    if (y != x)
    {
        if (string_equal(y, x))
            return 1;
    }
    return 0;
}

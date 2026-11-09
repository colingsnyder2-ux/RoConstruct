// from server: 90% by atomic.potato
struct S
{
    int padding[63];
};

extern "C" int __cdecl f();

int *g()
{
    int *value = (int *)f();
    if (value != 0)
    {
        value = *(int **)((char *)value + 0xf8);
        if (value != 0)
            return (int *)((char *)value - 0xa4);
    }
    return 0;
}

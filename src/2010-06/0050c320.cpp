// from server: 61% by atomic.potato
struct S
{
    void __cdecl f(void *, void *);
};

void __cdecl S::f(void *value, void *out)
{
    if (value)
    {
        *(void **)value = *(void **)out;
        *(void **)out = (char *)value + 0x70;
    }
    else
    {
        *(void **)out = 0;
    }
}

// from server: 56% by atomic.potato
struct S
{
};

void __cdecl f(void *a, void *b)
{
    if (a)
    {
        *(void **)a = *(void **)b;
        *(void **)b = (char *)a + 0x70;
    }
    else
    {
        *(void **)a = *(void **)b;
        *(void **)b = 0;
    }
}

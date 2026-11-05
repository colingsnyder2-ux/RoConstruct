// from server: 100% by atomic.potato
struct EventDesc
{
};

extern "C" void __cdecl helper(int, void *, int);

void __cdecl f(int a, void *p, int type)
{
    if (type != 4)
    {
        helper(a, p, type);
        return;
    }

    *(int *)p = 0xdb9898;
    ((char *)p)[4] = 0;
    ((char *)p)[5] = 0;
}

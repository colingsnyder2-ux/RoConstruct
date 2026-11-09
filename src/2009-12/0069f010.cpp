// from server: 77% by atomic.potato
struct S
{
};

int __cdecl f(void *p)
{
    if (p)
        return *(int *)((char *)p - 12);
    return *(int *)((char *)0 + 28);
}

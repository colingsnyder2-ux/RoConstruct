// from server: 96% by atomic.potato
struct S
{
};

void ** __cdecl f(void *p)
{
    void **e = p ? (void **)((char *)p + 0x30) : 0;
    void **d = (void **)*e;
    void **a = d;

    while (*a != e)
        a = (void **)*a;

    *a = d;
    return a;
}

// from server: 61% by atomic.potato
struct S
{
};

void __cdecl f(void *a, void *b, void *c)
{
    char *d = (char *)b;
    char *e = (char *)c;
    while (d != a)
    {
        d -= 4;
        e -= 4;
        *(void **)e = *(void **)d;
    }
}

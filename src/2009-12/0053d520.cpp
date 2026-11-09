// from server: 84% by atomic.potato
struct S
{
};

char __cdecl f(void *p)
{
    void **v = *(void ***)p;
    void *q = v[1];
    char *(*fn)(void *) = (char *(*)(void *))v[0];
    return *fn(q);
}

// from server: 100% by atomic.potato
struct S
{
};

void __cdecl f(void *a, void *b)
{
    typedef void (__cdecl *Fn)(void *, void *, void *);
    Fn fn = *(Fn *)a;
    fn(b, *(void **)((char *)a + 4), *(void **)((char *)a + 8));
}

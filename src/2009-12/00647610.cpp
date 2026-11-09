// from server: 53% by atomic.potato
struct V
{
    void *p;
    int f(int a, int b);
};

extern "C" int __stdcall call6474c0(void *, void *);

int V::f(int a, int b)
{
    void *p = *(void **)((char *)this + 0x1c);
    void *q = *(void **)p;
    void *r = *(void **)((char *)q + 0xc);
    void *s = &a;
    ((void *(__cdecl *)(void *, void *))r)(p, s);
    return call6474c0(&r, (void *)b);
}

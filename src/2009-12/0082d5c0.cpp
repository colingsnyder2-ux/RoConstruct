// from server: 90% by atomic.potato
extern "C" void __cdecl qsort(void *, unsigned int, unsigned int, int (__cdecl *)(const void *, const void *));

struct S
{
    char pad[36];
    void *a;
    unsigned int b;
    void f(void *);
};

void S::f(void *p)
{
    qsort(a, 4, b, (int (__cdecl *)(const void *, const void *))p);
}

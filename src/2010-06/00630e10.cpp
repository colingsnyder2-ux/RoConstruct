// from server: 89% by atomic.potato
extern "C" void imported_destroy(void *);
extern "C" void __cdecl cleanup(void *);

struct S
{
    void *pad[20];
    S *f(int);
};

S *S::f(int flag)
{
    S *p = (S *)((char *)this - 0x50);
    imported_destroy(p);
    if (flag & 1)
        cleanup(p);
    return p;
}

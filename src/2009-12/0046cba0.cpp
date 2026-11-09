// from server: 95% by atomic.potato
extern "C" void __cdecl Release(void *);

struct S
{
    void f(void *, void *);
};

void S::f(void *, void *)
{
    void *p = *(void **)((char *)this + 0xb8);
    if (p != 0)
    {
        Release(p);
        *(void **)((char *)this + 0xb8) = 0;
    }
    *(void **)((char *)this + 0xbc) = 0;
    *(void **)((char *)this + 0xc0) = 0;
}

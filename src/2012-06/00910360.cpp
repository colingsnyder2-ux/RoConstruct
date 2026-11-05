// from server: 100% by atomic.potato
extern "C" void __cdecl Function00910180(void *, void *);
extern "C" void __cdecl Function00982114(void *);

struct S
{
    void f();
};

void S::f()
{
    void *p = *(void **)((char *)this + 12);
    if (p)
    {
        Function00910180(p, *(void **)((char *)p + 12));
        Function00982114(p);
    }
}

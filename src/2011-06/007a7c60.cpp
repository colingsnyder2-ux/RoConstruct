// from server: 100% by atomic.potato
struct S
{
    char padding[0xc];
    void *member;
    void f();
};

extern "C" void __cdecl call_7a7af0(void *, int);
extern "C" void __cdecl call_80a058(void *);

void S::f()
{
    void *p = member;
    if (p)
    {
        call_7a7af0(p, *(int *)((char *)p + 0x14));
        call_80a058(p);
    }
}

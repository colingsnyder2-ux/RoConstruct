// from server: 79% by atomic.potato
extern "C" void ReleaseObject(void *);
extern "C" void __cdecl DeleteObject(void *);

struct S
{
    void f();
};

void S::f()
{
    void *p = *(void **)this;
    if (p)
    {
        ReleaseObject((char *)p + 0x18);
        DeleteObject(p);
    }
}

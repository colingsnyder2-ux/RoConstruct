// from server: 100% by atomic.potato
extern "C" void __fastcall sub_5ad190(void *);
extern "C" void __cdecl sub_6a067a(void *);

struct S
{
    void f();
};

void S::f()
{
    void *p = *(void **)this;
    if (p)
    {
        sub_5ad190((char *)p + 4);
        sub_6a067a(p);
    }
}

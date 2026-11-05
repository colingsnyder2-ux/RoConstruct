// from server: 82% by atomic.potato
extern "C" void __stdcall sub_7007B0(void *, void *);

struct S
{
    void __cdecl f(S *, S *);
};

void S::f(S *a, S *b)
{
    S *p = a;
    while (p != b)
    {
        sub_7007B0(p, this);
        *(void **)((char *)p + 0x20) = *(void **)((char *)this + 0x20);
        p = (S *)((char *)p + 0x28);
    }
}

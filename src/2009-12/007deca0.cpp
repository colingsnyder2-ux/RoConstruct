// from server: 62% by atomic.potato
extern "C" void __cdecl sub_006be120(void *, void *, void *);

struct S
{
    S * __cdecl f(S *);
};

S *S::f(S *p)
{
    sub_006be120(p, (void *)0x009efc90, 0);
    return p;
}

// from server: 100% by atomic.potato
extern "C" void __cdecl sub_007a9b00(void *, int);
extern "C" void __cdecl sub_0080a058(void *);

struct S
{
};

void __cdecl f(void *p)
{
    if (p)
    {
        sub_007a9b00(p, *((int *)p + 3));
        sub_0080a058(p);
    }
}

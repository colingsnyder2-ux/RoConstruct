// from server: 100% by atomic.potato
struct S
{
};

extern "C" void __cdecl sub_75bdf0(void *, int);
extern "C" void __cdecl sub_7a799a(void *);

void __cdecl f(void *p, int value)
{
    if (p)
    {
        sub_75bdf0(p, *(int *)((char *)p + 12));
        sub_7a799a(p);
    }
}

// from server: 91% by atomic.potato
extern "C" void __cdecl sub_80B1D8(void *, int, int, void *);
extern "C" void __cdecl sub_80A058(void *);

struct S
{
    char pad[12];
    void *field_0C;
    void f();
};

void S::f()
{
    void *p = field_0C;
    if (p)
    {
        sub_80B1D8((char *)p + 8, 0x28, 0x28, (void *)0x511610);
        sub_80A058(p);
    }
}

// from server: 79% by atomic.potato
extern "C" void __cdecl sub_0096C9B0(void *);
extern "C" void __cdecl sub_0080A058(void *);

struct S
{
    void f();
    void *value;
};

void S::f()
{
    void *p = value;
    if (p)
    {
        sub_0096C9B0((char *)p + 0x18);
        sub_0080A058(p);
    }
}

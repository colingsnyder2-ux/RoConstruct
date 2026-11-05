// from server: 100% by atomic.potato
struct S
{
    char pad[12];
    void *field_0c;
    void f();
};

extern "C" void __cdecl sub_756290(void *, unsigned long);
extern "C" void __cdecl sub_7A799A(void *);

void S::f()
{
    void *p = field_0c;
    if (p != 0)
    {
        sub_756290(p, *(unsigned long *)((char *)p + 12));
        sub_7A799A(p);
    }
}

// from server: 91% by atomic.potato
extern "C" void __cdecl sub_7A8ADE(void *, int, int, void *);
extern "C" void __cdecl sub_7A799A(void *);

struct S
{
    void f();
    char padding[12];
    void *field_0C;
};

void S::f()
{
    void *p = field_0C;
    if (p)
    {
        sub_7A8ADE((char *)p + 8, 0x18, 0x28, (void *)0x507810);
        sub_7A799A(p);
    }
}

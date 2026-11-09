// from server: 51% by atomic.potato
struct S
{
    static void __cdecl f(int, int);
};

extern "C" void __cdecl sub_7f4878(void *, void *);

void __cdecl S::f(int a, int b)
{
    struct T
    {
        int a;
        int b;
        int c;
        int d;
    } t;

    t.a = 0x9f1760;
    t.b = a;
    t.c = b;
    t.d = 0;
    sub_7f4878(&t, (void *)0xad5c04);
}

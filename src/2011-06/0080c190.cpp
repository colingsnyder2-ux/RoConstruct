// from server: 43% by atomic.potato
struct S
{
    void __cdecl f(int, int);
};

extern "C" void __cdecl g(void *, void *);

void __cdecl S::f(int a, int b)
{
    struct T
    {
        int x;
        int a;
        int b;
        int z;
    } t;

    t.x = (int)&t;
    t.a = a;
    t.b = b;
    t.z = 0;
    g(&t, (void *)0xbd39ac);
}

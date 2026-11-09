// from server: 44% by atomic.potato
struct S
{
    int value;
    int reserved[4];
    int member;
    int (**vtable)();
    void f();
};

extern "C" void __cdecl target();

void S::f()
{
    int (**table)();

    value = 0xB98FB8;
    member = 0xB98FB0;
    member = 0xB43E60;

    if (vtable != 0)
    {
        table = vtable;
        table[4]();
    }

    target();
}

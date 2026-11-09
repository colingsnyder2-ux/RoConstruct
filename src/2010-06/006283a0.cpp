// from server: 65% by atomic.potato
extern "C" void __stdcall sub_7A7976(void *, void *);

struct S
{
    int f(void *, void *);
};

int S::f(void *a, void *b)
{
    if (!b)
    {
        sub_7A7976(&b, a);
        if (b)
            ((void (__thiscall *)(void *))0x628350)(b);
    }
    return 0;
}

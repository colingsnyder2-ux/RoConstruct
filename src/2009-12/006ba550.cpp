// from server: 88% by atomic.potato
extern "C" void __stdcall sub_7f3836(void *, void *);

struct S
{
    int f(void *, void *);
};

struct T
{
    void __thiscall f(void *);
};

int S::f(void *a, void *c)
{
    if (c == 0)
    {
        sub_7f3836(a, &c);
        if (c != 0)
            ((T *)c)->f(c);
    }
    return 0;
}

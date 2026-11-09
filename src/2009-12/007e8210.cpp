// from server: 48% by atomic.potato
extern "C" void __cdecl f(void *);

struct S
{
    int *begin;
    int *end;
    int *current;
    int unused;
    int count;
    void f();
};

void S::f()
{
    unsigned int i = 0;
    while (i < (unsigned int)count)
    {
        current += 2;
        if (current == end)
            current = begin;
        ++i;
    }

    if (*begin != 0)
        ::f((void *)*begin);
}

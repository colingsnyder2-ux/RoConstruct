// from server: 79% by atomic.potato
struct S
{
    char pad00[0x15];
    char value15;
    char pad16[2];
    int value18;

    void f(void *arg);
};

extern "C" void __stdcall Call58A6F0(void *);

void S::f(void *arg)
{
    if (value18 == 0)
    {
        if (value15 == 0)
        {
            value18 = *(int *)arg;
            if (value15 == 0)
            {
                Call58A6F0((void *)*(int *)((char *)arg + 0x170));
                value15 = 1;
            }
        }
    }
}

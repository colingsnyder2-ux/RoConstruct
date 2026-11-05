// from server: 21% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    int *ebx = (int *)0x51d433;
    int *ebp = (int *)0x51d440;
    int *esi = ebx;

    do
    {
        while (esi != ebx)
            esi = ebx;
        ebx += 1;
    }
    while (ebx != ebp);
}

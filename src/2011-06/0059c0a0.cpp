// from server: 55% by atomic.potato
struct S
{
    int f();
    int pad0[41];
    int value;
    int pad1[10];
};

void __stdcall g(S *);

int S::f()
{
    if (value == 1)
        return 0;

    value = 2;
    g((S *)((char *)this + 0xd0));
    return 0;
}

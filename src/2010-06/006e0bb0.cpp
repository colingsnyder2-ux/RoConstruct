// from server: 76% by atomic.potato
struct S
{
    char pad[0x1d4];
    int value;
    void f(int);
};

void __thiscall S::f(int v)
{
    if (value != v)
    {
        value = v;
        *(int*)0x40c470 = 0xc20f78;
    }
}

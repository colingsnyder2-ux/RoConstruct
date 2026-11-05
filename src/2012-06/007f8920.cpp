// from server: 100% by tajop
struct S
{
    unsigned long value;
    unsigned long pad;
    unsigned long data;
    unsigned long limit;
    void __thiscall f(unsigned long);
    void __thiscall g(unsigned long);
};

void __thiscall S::f(unsigned long n)
{
    while (limit > n)
    {
        g(*((unsigned long*)data + 1) + 8);
    }
}

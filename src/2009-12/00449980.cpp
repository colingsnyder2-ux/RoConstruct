// from server: 100% by atomic.potato
struct S
{
    char padding[208];
    int field_D0;
    void f(int value);
};

extern "C" void __stdcall G1_func_0040C080(int value);

void S::f(int value)
{
    if (value != field_D0)
    {
        field_D0 = value;
        G1_func_0040C080(0xB7B178);
    }
}

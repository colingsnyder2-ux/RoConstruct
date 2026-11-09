// from server: 100% by atomic.potato
extern "C" void __stdcall G1_func_0040C080(int);

struct S
{
    void f(int value);
    char padding[196];
    int field_C4;
};

void S::f(int value)
{
    if (value != field_C4)
    {
        field_C4 = value;
        G1_func_0040C080(0xB7B100);
    }
}

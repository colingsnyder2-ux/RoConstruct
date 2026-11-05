// from server: 100% by atomic.potato
struct S
{
    void f(int value);
    char padding[184];
    int field;
};

extern "C" void __stdcall G1_func_0040c080(int);

void S::f(int value)
{
    if (value != field)
    {
        field = value;
        G1_func_0040c080(0xB7B088);
    }
}

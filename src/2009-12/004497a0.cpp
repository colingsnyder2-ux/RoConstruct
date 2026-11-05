// from server: 100% by atomic.potato
extern "C" void __stdcall G1_func_0040c080(int);

struct S
{
    char padding[168];
    int value;
    void f(int);
};

void S::f(int v)
{
    if (v != value)
    {
        value = v;
        G1_func_0040c080(0x00b7afe8);
    }
}

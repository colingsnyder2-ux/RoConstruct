// from server: 100% by atomic.potato
extern "C" void __stdcall G1_func_0040C080(int);

struct S
{
    int pad[43];
    int value;
    void f(int);
};

void S::f(int v)
{
    if (v != value)
    {
        value = v;
        G1_func_0040C080(0x00B7AE68);
    }
}

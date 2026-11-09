// from server: 83% by atomic.potato
struct S
{
    void f(double, double);
};

extern "C" void G1_func_0059a3c0(S *, double, double);

void S::f(double a, double b)
{
    G1_func_0059a3c0((S *)((char *)this + 0x10), b, a);
}

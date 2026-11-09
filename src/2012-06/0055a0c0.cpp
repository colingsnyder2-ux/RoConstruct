// from server: 40% by atomic.potato
extern "C" void __stdcall S_func_00414da0(int);

struct S_func_0055a0c0
{
    char pad0[0xd8];
    double m_value;
    void f(double a, double b);
};

void S_func_0055a0c0::f(double a, double b)
{
    double lo = 0.0;
    double hi = 0.0;
    double v = a;
    if (v > b)
        v = b;
    double w = a;
    if (w > b)
        w = b;
    double r = v;
    if (r > w)
        r = w;
    if (r != m_value)
    {
        m_value = r;
        S_func_00414da0(0x00e23918);
    }
}

// from server: 45% by atomic.potato
struct S_func_006cb860
{
    char pad[0xe8];
    double m_field_e8;
    void f(double a, double b);
};

extern "C" void __stdcall sub_007e5d40(double* out, double a);

void S_func_006cb860::f(double a, double b)
{
    double tmp;
    sub_007e5d40(&tmp, a);
    m_field_e8 = tmp + b;
}

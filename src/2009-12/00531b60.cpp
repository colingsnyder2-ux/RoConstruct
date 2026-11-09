// from server: 57% by atomic.potato
struct S_func_007e7950
{
    double m_value;
    char m_flag;
    char m_padding[3];
};

extern "C" void __stdcall S_func_007e7950_impl(
    S_func_007e7950 *result,
    const double *value,
    double multiplier);

struct S_func_00531b60
{
    void f();
};

void S_func_00531b60::f()
{
    double value = 1.333333;
    S_func_007e7950_impl((S_func_007e7950 *)this, &value, 1.0);
}

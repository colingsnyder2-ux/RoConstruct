// from server: 90% by Intel
struct S_func_0071ed80 {
    char pad[20];
    int m_value;
    double f();
};
double S_func_0071ed80::f()
{
    extern const double divisor;
    return divisor / static_cast<double>(m_value);
}

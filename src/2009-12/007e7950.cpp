// from server: 100% by atomic.potato
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

void __stdcall S_func_007e7950_impl(
    S_func_007e7950 *result,
    const double *value,
    double multiplier)
{
    result->m_value = (*value) * multiplier;
    result->m_flag = 0;
}

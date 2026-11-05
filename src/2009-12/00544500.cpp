// from server: 65% by atomic.potato
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

struct PingJob
{
    void f(S_func_007e7950 *result);
};

double g_value;

void PingJob::f(S_func_007e7950 *result)
{
    S_func_007e7950_impl(result, &g_value, g_value);
}

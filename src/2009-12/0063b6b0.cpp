// from server: 51% by atomic.potato
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

struct HeartbeatTask
{
    char m_padding[0x1e0];
    double m_value;
    int f(int a, S_func_007e7950 *result);
};

int HeartbeatTask::f(int a, S_func_007e7950 *result)
{
    double value = m_value;
    S_func_007e7950_impl(result, &value, a);
    return a;
}

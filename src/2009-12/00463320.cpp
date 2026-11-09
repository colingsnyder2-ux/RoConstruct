// from server: 66% by atomic.potato
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

struct UserInputJob
{
    UserInputJob *f(void *, void *);
};

double g_value;

UserInputJob *UserInputJob::f(void *a, void *b)
{
    S_func_007e7950_impl((S_func_007e7950 *)b, &g_value, *(double *)&a);
    return (UserInputJob *)b;
}

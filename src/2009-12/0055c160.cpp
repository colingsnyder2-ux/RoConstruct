// from server: 53% by atomic.potato
struct S_func_007e7950
{
    double m_value;
    char m_flag;
    char m_padding[3];
};

extern "C" void *S_func_00523e90(void *object);
extern "C" void __stdcall S_func_007e7950_impl(
    S_func_007e7950 *result,
    const double *value,
    double multiplier);

struct NetworkOwnerJob
{
    int f(int, int);
};

int NetworkOwnerJob::f(int a, int b)
{
    void *p;
    double value;
    S_func_007e7950 result;

    p = this;
    p = S_func_00523e90(p);
    value = *(float *)((char *)p + 0xd8);
    S_func_007e7950_impl(&result, &value, (double)b);
    return b;
}

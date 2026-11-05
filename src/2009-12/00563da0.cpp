// from server: 46% by atomic.potato
struct S_func_007e7950
{
    double m_value;
    char m_flag;
    char m_padding[3];
};

extern "C" void *S_func_00523e90(void *);

extern "C" void __stdcall S_func_007e7950_impl(
    S_func_007e7950 *, const double *, double);

struct PacketReceiveJob
{
    int f(int, int);
};

int PacketReceiveJob::f(int a, int b)
{
    void *value = S_func_00523e90(this);
    S_func_007e7950_impl((S_func_007e7950 *)this, (const double *)value,
                         (double)a);
    return b;
}

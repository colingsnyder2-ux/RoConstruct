// from server: 63% by atomic.potato
extern "C" void __stdcall G1_func_0065bbd0(void*, const char*, double, double);

struct S
{
    void f(double*);
};

void S::f(double* value)
{
    G1_func_0065bbd0(this, "%.3g", *value, *value);
}

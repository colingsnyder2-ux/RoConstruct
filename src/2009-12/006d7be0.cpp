// from server: 67% by atomic.potato
extern "C" void __cdecl G1_func_006d7b60(const char*, double, double);

struct S
{
    void f(double*);
};

void S::f(double* value)
{
    G1_func_006d7b60("%.3g", *value, *value);
}

// from server: 84% by atomic.potato
struct Motor6D
{
    void f(float *value);
};

extern "C" void __stdcall G1_func_0091db40(float *, float *, float, float);

void Motor6D::f(float *value)
{
    G1_func_0091db40(value, value + 3, value[6], value[7]);
}

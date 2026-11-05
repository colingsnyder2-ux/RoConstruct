// from server: 71% by atomic.potato
struct S_func_00677700
{
    virtual float f();
    int g(float *, float);
};

int S_func_00677700::g(float *a, float b)
{
    return f() < a[10] - b;
}

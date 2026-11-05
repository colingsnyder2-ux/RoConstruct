// from server: 100% by atomic.potato
extern "C" void G1_func_0065bbd0(void *, double, const char *, double);

struct S
{
    void f(float *);
};

void S::f(float *p)
{
    double d = *p;
    G1_func_0065bbd0(this, d, "%.3g", d);
}

// from server: 62% by atomic.potato
extern "C" void __stdcall G1_func_00414da0(const char *);

struct S {
    char padding[584];
    double value;
    void f(double);
};

void S::f(double x)
{
    if (x > value)
        return;

    value = x;
    G1_func_00414da0("\\$ ;");
}

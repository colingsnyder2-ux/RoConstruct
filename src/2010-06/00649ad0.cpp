// from server: 61% by atomic.potato
extern "C" void __cdecl sub_00649a50(double, double, const char *, void *);

struct S_func_00649ad0
{
    void f(double *);
};

void S_func_00649ad0::f(double *value)
{
    sub_00649a50(*value, *value, "%.3g", this);
}

// from server: 93% by atomic.potato
struct S
{
    void f(double, double);
};

void __fastcall call_target(S *, double, double);

void S::f(double a, double b)
{
    call_target((S *)((char *)this + 16), b, a);
}

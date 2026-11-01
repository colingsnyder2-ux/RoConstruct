// from server: 100% by atomic.potato
struct S
{
    double method();
};

extern "C" void __cdecl sub_4f15e0(int n, double d);

void f(S *s, int n)
{
    double v = s->method();
    sub_4f15e0(n, v);
}

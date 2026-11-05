// from server: 32% by atomic.potato
extern "C" void __cdecl sub_009092d5(int);
extern "C" void __cdecl sub_00C9B648(int, int, int, int, int, float, int);

struct S_func_00906f40
{
    void f(int, int, int, int, int, float);
};

void S_func_00906f40::f(int a, int b, int c, int d, int e, float f)
{
    sub_009092d5(1);
    sub_00C9B648(a, b, c, d, e, f, 0);
}

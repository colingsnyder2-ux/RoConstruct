// from server: 40% by atomic.potato
extern "C" void __cdecl sub_009092d5(int);

extern "C" void __cdecl imported_00C9B5E0(
    int, int, int, int, int, float);

struct S_func_009040c8
{
    void f(int, int, int, int, int, float);
};

void S_func_009040c8::f(int a, int b, int c, int d, int e, float x)
{
    sub_009092d5(1);
    imported_00C9B5E0(a, b, c, d, e, x);
}

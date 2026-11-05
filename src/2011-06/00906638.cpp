// from server: 48% by atomic.potato
extern "C" void __cdecl sub_009092D5(int);

extern "C" void __stdcall sub_00C9B6BC(
    int, float, int, float, int);

struct S_func_00906638
{
    void f(int, float, int, int, float);
};

void S_func_00906638::f(int a, float b, int c, int d, float e)
{
    sub_009092D5(1);
    sub_00C9B6BC(a, b, c, d, e);
}

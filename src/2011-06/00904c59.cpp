// from server: 35% by atomic.potato
extern "C" void __cdecl sub_009092D5(int);

extern "C" void __cdecl sub_00C9B670(
    int, int, int, int, int, int, float);

struct S_func_00904C59 {
    void f(int, int, int, int, int, float);
};

void S_func_00904C59::f(int a, int b, int c, int d, int e, float value)
{
    sub_009092D5(1);
    sub_00C9B670(a, b, c, d, e, 1, value);
}

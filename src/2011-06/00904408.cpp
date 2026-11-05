// from server: 40% by atomic.potato
extern "C" void __cdecl sub_009092D5(int);

extern "C" int __cdecl sub_00C9B660(int, int, int, int, int, float);

struct S_func_00904408
{
    int f(int, int, int, int, int, float);
};

int S_func_00904408::f(int a, int b, int c, int d, int e, float f)
{
    sub_009092D5(1);
    return sub_00C9B660(a, b, c, d, e, f);
}

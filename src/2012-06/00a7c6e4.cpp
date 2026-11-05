// from server: 41% by atomic.potato
extern "C" void __cdecl sub_a814d5(int);

extern "C" int __stdcall sub_e0863c(int, int, int, int, int, float);

struct S
{
    int f(int, int, int, int, int, float);
};

int S::f(int a, int b, int c, int d, int e, float value)
{
    sub_a814d5(1);
    return sub_e0863c(a, b, c, d, e, value);
}

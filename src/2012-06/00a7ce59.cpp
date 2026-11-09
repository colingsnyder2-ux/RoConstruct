// from server: 23% by atomic.potato
extern "C" void __stdcall sub_a814d5(int);

extern "C" void __stdcall sub_e08648(int, int, int, int, int, float);

struct S
{
    void f(int, int, int, int, int, float);
};

void S::f(int a, int b, int c, int d, int e, float v)
{
    sub_a814d5(1);
    sub_e08648(a, b, c, d, e, v);
}

// from server: 41% by atomic.potato
extern "C" void __cdecl sub_a814d5(int);

extern "C" void __stdcall imported_QQVW(
    int, int, int, int, int, float);

struct S
{
    void f(int, int, int, int, int, float);
};

void S::f(int a, int b, int c, int d, int e, float value)
{
    sub_a814d5(1);
    imported_QQVW(a, b, c, d, e, value);
}

// from server: 41% by atomic.potato
extern "C" void __stdcall sub_005c3720(int, int, short, short, int);

struct S
{
    void __stdcall f(int, int, short, short, int);
};

void __stdcall S::f(int a, int b, short c, short d, int e)
{
    sub_005c3720(a, b, c, d, e);
}

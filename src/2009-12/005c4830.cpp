// from server: 45% by atomic.potato
extern "C" void __cdecl sub_005c3b40(short, short, int, int);

struct S
{
    void f(short, short, int, int);
};

void S::f(short a, short b, int c, int d)
{
    sub_005c3b40(a, b, c, d);
}

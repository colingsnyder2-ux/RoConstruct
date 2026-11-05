// from server: 45% by atomic.potato
extern "C" void __cdecl sub_0061db10(short, short, short, int);

struct S
{
    void f(short, short, short, int);
};

void S::f(short a, short b, short c, int d)
{
    sub_0061db10(a, b, c, d);
}

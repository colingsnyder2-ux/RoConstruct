// from server: 47% by atomic.potato
extern "C" void __stdcall sub_005c73d0(short, short, short, short);

struct S
{
    void f(short, short, short, short, int);
};

void S::f(short a, short b, short c, short d, int e)
{
    sub_005c73d0(a, b, c, d);
}

// from server: 48% by atomic.potato
extern "C" void __cdecl sub_009300a0(short, short, short, short);

struct S
{
    void f(short, short, short, short, short);
};

void S::f(short a, short b, short c, short d, short e)
{
    sub_009300a0(a, b, c, d);
}

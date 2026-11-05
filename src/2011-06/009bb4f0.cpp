// from server: 45% by atomic.potato
extern "C" void __cdecl sub_009ba820(short, short, short, short);

struct S
{
    void f(short, short, short, short);
};

void S::f(short a, short b, short c, short d)
{
    sub_009ba820(a, b, c, d);
}

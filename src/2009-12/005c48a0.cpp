// from server: 48% by atomic.potato
extern "C" void __cdecl sub_5c4380(short, short, long, long);

struct S
{
    void f(short a, short b, long c, long d, long e);
};

void S::f(short a, short b, long c, long d, long e)
{
    sub_5c4380(a, b, c, d);
}

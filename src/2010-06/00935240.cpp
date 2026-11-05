// from server: 47% by atomic.potato
extern "C" void __stdcall sub_009344F0(short, short, short, short);

struct S
{
    void f(short, short, short, short, short);
};

void S::f(short a, short b, short c, short d, short e)
{
    sub_009344F0(c, d, e, a);
}

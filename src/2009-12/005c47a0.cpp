// from server: 43% by atomic.potato
extern "C" void __cdecl sub_5c2ee0(short, short, short, int);

struct S
{
    void f(short, short, short, int);
};

void S::f(short a, short b, short c, int d)
{
    sub_5c2ee0(c, b, a, d);
}

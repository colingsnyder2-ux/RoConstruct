// from server: 48% by atomic.potato
struct S
{
    void f(short, short, int, int, int);
};

extern "C" void __cdecl sub_5c8090(int, int, short, short);

void S::f(short a, short b, int c, int d, int e)
{
    sub_5c8090(e, d, b, a);
}

// from server: 46% by atomic.potato
extern "C" void __cdecl sub_61ced0(short, short, int, int);

struct S
{
    void f(short, short, int);
};

void S::f(short a, short b, int c)
{
    sub_61ced0(a, b, a, c);
}

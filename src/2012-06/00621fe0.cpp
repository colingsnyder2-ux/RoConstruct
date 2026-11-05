// from server: 45% by atomic.potato
extern "C" void __cdecl sub_620790(short, short, short, int);

struct TorsoBuilder
{
    void f(short, short, short, int);
};

void TorsoBuilder::f(short a, short b, short c, int d)
{
    sub_620790(a, b, c, d);
}

// from server: 37% by atomic.potato
struct TorsoBuilder
{
    void f(short a, short b, short c, int d);
};

extern "C" void __cdecl sub_009be990(short, short, short, int);

void TorsoBuilder::f(short a, short b, short c, int d)
{
    sub_009be990(a, c, b, d);
}

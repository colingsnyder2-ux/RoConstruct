// from server: 49% by atomic.potato
extern "C" void __stdcall sub_009bdcf0(int, int, short, short, int);

struct TorsoBuilder
{
    void f(int, int, short, short, int);
};

void TorsoBuilder::f(int a, int b, short c, short d, int e)
{
    sub_009bdcf0(a, b, d, c, e);
}

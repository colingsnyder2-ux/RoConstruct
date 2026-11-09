// from server: 44% by atomic.potato
extern "C" void __stdcall sub_0092fc90(short, short, short, int);

struct S
{
    void __stdcall f(short, short, short, int);
};

void __stdcall S::f(short a, short b, short c, int d)
{
    sub_0092fc90(a, b, c, d);
}

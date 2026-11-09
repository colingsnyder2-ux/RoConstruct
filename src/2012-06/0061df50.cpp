// from server: 41% by atomic.potato
extern "C" void __cdecl call_0061cac0(
    unsigned short,
    unsigned short,
    unsigned short,
    unsigned short,
    unsigned long);

struct S
{
    void f(unsigned short, unsigned short, unsigned short, unsigned long);
};

void S::f(unsigned short a, unsigned short b, unsigned short c, unsigned long d)
{
    call_0061cac0(0, a, b, c, d);
}

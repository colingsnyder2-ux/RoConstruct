// from server: 46% by atomic.potato
struct S
{
    void __stdcall f(unsigned short, unsigned short, unsigned long, unsigned long);
};

extern "C" void __stdcall sub_009308d0(unsigned long, unsigned long, unsigned long, unsigned long);

void __stdcall S::f(unsigned short a, unsigned short b, unsigned long c, unsigned long d)
{
    sub_009308d0(d, c, b, a);
}

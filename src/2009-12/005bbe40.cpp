// from server: 45% by atomic.potato
extern "C" void __stdcall sub_5b92e0(unsigned short, unsigned short, unsigned long);

void __stdcall sub_5bbe40(unsigned short a, unsigned short b, unsigned short c, unsigned long d)
{
    a = c;
    sub_5b92e0(a, b, d);
}

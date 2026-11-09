// from server: 50% by atomic.potato
extern "C" void __stdcall sub_95d0e0(unsigned int, unsigned int, unsigned short, unsigned short);

void __stdcall sub_95fc30(unsigned short a, unsigned short b, unsigned short c, unsigned int d)
{
    sub_95d0e0(d, a, c, b);
}

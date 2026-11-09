// from server: 44% by atomic.potato
extern "C" void __stdcall sub_005c77f0(unsigned int, unsigned int, unsigned int);

void __stdcall sub_005c8d80(unsigned short a, unsigned short b,
                             unsigned int c, unsigned int d)
{
    sub_005c77f0(c, b, d);
}

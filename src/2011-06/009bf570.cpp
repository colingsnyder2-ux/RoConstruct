// from server: 42% by atomic.potato
extern "C" void __stdcall sub_009be100(short, short, unsigned long);

void __stdcall sub_009bf570(short a, short b, unsigned long c, unsigned short d)
{
    sub_009be100(a, b, c);
}

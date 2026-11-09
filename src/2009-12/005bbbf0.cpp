// from server: 42% by atomic.potato
extern "C" void __stdcall sub_005ba730(unsigned long, unsigned long, unsigned long);

void __stdcall sub_005bbbf0(unsigned long a, unsigned long b, unsigned long c, unsigned long d)
{
    sub_005ba730(b, d, a);
}

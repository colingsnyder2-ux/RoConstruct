// from server: 42% by atomic.potato
extern "C" void __stdcall sub_009ab650(unsigned short, unsigned short, unsigned long);

void __stdcall sub_009ace60(unsigned short a, unsigned short b, unsigned short c, unsigned long d)
{
    sub_009ab650(a, b, d);
}

// from server: 42% by atomic.potato
extern "C" void __stdcall sub_5b9f10(short, short, int);

void __stdcall sub_5bbe70(short a, short b, short c, int d)
{
    sub_5b9f10(a, b, d);
}

// from server: 42% by atomic.potato
extern "C" unsigned short __stdcall sub_0095dd00(
    unsigned short,
    unsigned short,
    unsigned long);

unsigned short __stdcall sub_0095fc60(
    unsigned short a,
    unsigned short b,
    unsigned short c,
    unsigned long d)
{
    return sub_0095dd00(a, b, d);
}

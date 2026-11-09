// from server: 42% by atomic.potato
extern "C" unsigned short __stdcall sub_60d010(
    unsigned short,
    unsigned short,
    unsigned long);

unsigned short __stdcall function_0060fae0(
    unsigned short a,
    unsigned short b,
    unsigned long c,
    unsigned short d)
{
    return sub_60d010(a, b, c);
}

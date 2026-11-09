// from server: 42% by atomic.potato
extern "C" short __stdcall sub_5c8940(short, short, long);

short __stdcall sub_5c8e60(short a, short b, short c, long d)
{
    return sub_5c8940(a, b, d);
}

// from server: 86% by atomic.potato
typedef unsigned char BYTE;

extern "C" void __cdecl Function9831F5(const void *);

volatile int g495F0;
volatile int g495E8;
volatile int g495EC;

void Function797E70()
{
    if ((g495F0 & 1) == 0)
    {
        g495F0 |= 1;
        g495E8 = 0;
        g495EC = 0;
        Function9831F5((const void *)0x00B1BA40);
    }
}

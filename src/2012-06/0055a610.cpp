// from server: 86% by atomic.potato
extern "C" void __cdecl sub_009831f5(const char *);

volatile unsigned long g_00e23c64;
volatile unsigned long g_00e23c5c;
volatile unsigned long g_00e23c60;

void f_0055a610()
{
    if (!(g_00e23c64 & 1))
    {
        g_00e23c64 |= 1;
        g_00e23c5c = 0;
        g_00e23c60 = 0;
        sub_009831f5((const char *)0x00b14290);
    }
}

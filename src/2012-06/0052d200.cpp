// from server: 89% by atomic.potato
typedef unsigned char Byte;

extern "C" void G_009831f5(const char *);

volatile unsigned long g_00e200e8;
volatile unsigned long g_00e200e0;
volatile unsigned long g_00e200e4;

void func_0052d200()
{
    if ((g_00e200e8 & 1) == 0)
    {
        g_00e200e8 |= 1;
        g_00e200e0 = 0;
        g_00e200e4 = 0;
        G_009831f5("8csm");
    }
}

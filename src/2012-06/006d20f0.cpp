// from server: 91% by atomic.potato
extern "C" void sub_009831f5(const char*);

volatile unsigned char g_00e2f92c;
volatile int g_00e2f924;
volatile int g_00e2f928;

void func_006d20f0()
{
    if (!g_00e2f92c)
    {
        *(volatile int*)&g_00e2f92c |= 1;
        g_00e2f924 = 0;
        g_00e2f928 = 0;
        sub_009831f5("8csm");
    }
}

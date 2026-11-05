// from server: 89% by atomic.potato
extern "C" void G1_func_009831f5(const char*);

volatile unsigned long g_00e5530c;
volatile unsigned long g_00e55304;
volatile unsigned long g_00e55308;

void func_008d6aa0()
{
    if (!(g_00e5530c & 1))
    {
        g_00e5530c |= 1;
        g_00e55304 = 0;
        g_00e55308 = 0;
        G1_func_009831f5("8csm");
    }
}

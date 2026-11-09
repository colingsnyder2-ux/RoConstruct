// from server: 83% by atomic.potato
typedef unsigned char BYTE;

extern "C" void __cdecl Function_9831F5(const char *);

volatile BYTE g_flag_00E4F480;
volatile int g_value_00E4F478;
volatile int g_value_00E4F47C;

void Function_007FAAC0()
{
    if (!g_flag_00E4F480)
    {
        g_flag_00E4F480 |= 1;
        g_value_00E4F478 = 0;
        g_value_00E4F47C = 0;
        Function_9831F5("8csm");
    }
}

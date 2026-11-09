// from server: 81% by atomic.potato
extern "C" void __cdecl Function_009831f5(const char*);

volatile unsigned char g_flag_00e53660;
volatile int g_value_00e53658;
volatile int g_value_00e5365c;

void Function_008c6200()
{
    if ((g_flag_00e53660 & 1) == 0)
    {
        g_flag_00e53660 |= 1;
        g_value_00e53658 = 0;
        g_value_00e5365c = 0;
        Function_009831f5("8csm");
    }
}

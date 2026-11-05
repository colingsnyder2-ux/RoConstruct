// from server: 89% by atomic.potato
extern "C" void __cdecl function_009831f5(const char *);

volatile unsigned long g_flag_00e4dfa4;
volatile unsigned long g_value_00e4df9c;
volatile unsigned long g_value_00e4dfa0;

void function_007d7500()
{
    if ((g_flag_00e4dfa4 & 1) == 0)
    {
        g_flag_00e4dfa4 |= 1;
        g_value_00e4df9c = 0;
        g_value_00e4dfa0 = 0;
        function_009831f5("8csm");
    }
}

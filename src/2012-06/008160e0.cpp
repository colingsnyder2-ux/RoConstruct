// from server: 89% by atomic.potato
extern "C" void __cdecl sub_9831f5(const char*);

volatile unsigned long g_flag_00e505c8;
volatile unsigned long g_value_00e505c0;
volatile unsigned long g_value_00e505c4;

void sub_8160e0()
{
    if ((g_flag_00e505c8 & 1) != 0)
        return;

    g_flag_00e505c8 |= 1;
    g_value_00e505c0 = 0;
    g_value_00e505c4 = 0;
    sub_9831f5("8csm");
}

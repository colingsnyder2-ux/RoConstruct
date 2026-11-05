// from server: 89% by atomic.potato
extern "C" void __cdecl sub_9831F5(const char *);

volatile unsigned long g_00E505BC;
volatile unsigned long g_00E505B4;
volatile unsigned long g_00E505B8;

void sub_00816020()
{
    if ((g_00E505BC & 1) != 0)
        return;

    g_00E505BC |= 1;
    g_00E505B4 = 0;
    g_00E505B8 = 0;
    sub_9831F5("8csm");
}

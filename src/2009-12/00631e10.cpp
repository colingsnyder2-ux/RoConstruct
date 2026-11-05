// from server: 81% by atomic.potato
extern "C" void __cdecl sub_007f4929(const char*);

volatile unsigned char g_flag = 0;
volatile int g_value = 0;

int sub_00631e10()
{
    if ((g_flag & 1) == 0)
    {
        *(volatile int*)&g_flag |= 1;
        g_value = 0;
        sub_007f4929("8csm");
    }
    return 1;
}

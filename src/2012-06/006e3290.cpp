// from server: 75% by atomic.potato
typedef unsigned char BYTE;
typedef unsigned long DWORD;

extern "C" void __cdecl sub_9831F5();

volatile BYTE g_flag = *(volatile BYTE*)0x00E2FEF8;
volatile DWORD& g_value0 = *(volatile DWORD*)0x00E2FEF0;
volatile DWORD& g_value1 = *(volatile DWORD*)0x00E2FEF4;

void f()
{
    if (g_flag & 1)
        return;

    g_flag |= 1;
    g_value0 = 0;
    g_value1 = 0;
    sub_9831F5();
}

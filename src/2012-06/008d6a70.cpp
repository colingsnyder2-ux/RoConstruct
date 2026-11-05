// from server: 89% by atomic.potato
typedef unsigned char byte;
typedef unsigned long DWORD;

extern "C" void __cdecl func_009831f5(const char *);

volatile unsigned long g_00e55300;
volatile DWORD g_00e552f8;
volatile DWORD g_00e552fc;

void func_008d6a70()
{
    if (!(g_00e55300 & 1))
    {
        g_00e55300 |= 1;
        g_00e552f8 = 0;
        g_00e552fc = 0;
        func_009831f5("8csm");
    }
}

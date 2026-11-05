// from server: 100% by atomic.potato
typedef unsigned char BYTE;
typedef unsigned long DWORD;

extern DWORD g_flag;
extern DWORD g_value1;
extern DWORD g_value2;

extern "C" void __cdecl function_009831f5(const char*);

void function_0081cc00()
{
    if ((g_flag & 1) == 0)
    {
        g_flag |= 1;
        g_value1 = 0;
        g_value2 = 0;
        function_009831f5((const char*)0x00b1e620);
    }
}

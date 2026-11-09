// from server: 100% by atomic.potato
typedef unsigned long DWORD;

extern "C" DWORD __declspec(dllimport) __stdcall TlsAlloc();

volatile unsigned char g_00ccdf04;
volatile DWORD g_00ccdf00;

void f_0066aed0(unsigned char value)
{
    g_00ccdf04 = value;
    g_00ccdf00 = TlsAlloc();
}

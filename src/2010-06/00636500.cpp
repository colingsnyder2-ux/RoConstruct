// from server: 100% by atomic.potato
typedef unsigned long DWORD;

extern "C" DWORD __declspec(dllimport) __stdcall TlsAlloc();

unsigned char g_tlsIndex;
DWORD g_tlsAllocResult;

void f(unsigned char value)
{
    g_tlsIndex = value;
    g_tlsAllocResult = TlsAlloc();
}

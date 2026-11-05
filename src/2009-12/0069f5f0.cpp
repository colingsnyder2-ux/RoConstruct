// from server: 100% by atomic.potato
typedef unsigned long DWORD;

extern DWORD g_b62b64;

extern "C" void __cdecl target_78a660(DWORD, DWORD, DWORD);

void f(DWORD a, DWORD b)
{
    target_78a660(a, b, g_b62b64);
}

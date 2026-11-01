// from server: 100% by atomic.potato
typedef unsigned long DWORD;

extern DWORD g_value;
extern "C" void __cdecl universal_tool(DWORD, DWORD, DWORD);

struct S
{
};

void __cdecl f(DWORD a, DWORD b)
{
    universal_tool(a, b, g_value);
}

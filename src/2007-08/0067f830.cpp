// from server: 100% by colin
extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char*);
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void*, const char*);

void func_0067f830(int a, int b)
{
    void* h = GetModuleHandleA("GDI32.DLL");
    void* p = GetProcAddress(h, "SetLayout");
    if (p)
        ((void (__stdcall*)(int, int))p)(a, b);
}

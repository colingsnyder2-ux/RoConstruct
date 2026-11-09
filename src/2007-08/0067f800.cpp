// from server: 100% by colin
extern "C" void* (__stdcall *GetModuleHandleA)(const char*);
extern "C" void* (__stdcall *GetProcAddress)(void*, const char*);

typedef int (__stdcall *GetLayoutFn)(void*);

int __cdecl sub_0067f800(void* arg)
{
    void* h = GetModuleHandleA("GDI32.DLL");
    GetLayoutFn fn = (GetLayoutFn)GetProcAddress(h, "GetLayout");
    if (fn == 0)
        return 0;
    return fn(arg);
}

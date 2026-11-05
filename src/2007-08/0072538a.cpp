// from server: 60% by colin
extern "C" {
    __declspec(dllimport) void* __stdcall GetProcessHeap(void);
    __declspec(dllimport) void* __stdcall HeapAlloc(void*, unsigned long, unsigned long);
    __declspec(dllimport) void* __stdcall VirtualAlloc(void*, unsigned long, unsigned long, unsigned long);
    __declspec(dllimport) int __stdcall VirtualFree(void*, unsigned long, unsigned long);
    __declspec(dllimport) void* __stdcall GetModuleHandleA(const char*);
    __declspec(dllimport) void* __stdcall GetProcAddress(void*, const char*);
}

extern int g_8c98b4;
extern void* g_8c98b8;
extern void* g_8c98bc;

void sub_7252af(int);
int sub_7252d5(void);

int f(int a)
{
    sub_7252af(a);
    return 0;
}

int g(void)
{
    if (g_8c98b4 == 0) {
        if (sub_7252d5() == 0)
            return 0;
    }
    if (g_8c98b4 == 1) {
        void* h = GetModuleHandleA((const char*)0);
        (void)h;
        if (GetProcAddress(0, (const char*)0xd) == 0)
            return 0;
        return 0;
    }
    if (((int (__cdecl*)(int))g_8c98bc)(g_8c98b4) != 0)
        return 0;
    void* p = VirtualAlloc(0, 0x1000, 0x1000, 0x40);
    if (p == 0)
        return 0;
    void* q = (void*)((int (__cdecl*)(int))g_8c98bc)(g_8c98b4);
    if (q != 0) {
        VirtualFree(p, 0, 0x8000);
        return (int)q;
    }
    char* end = (char*)p + 0xff0;
    char* cur = (char*)p;
    do {
        ((void (__cdecl*)(int, void*))g_8c98b8)(g_8c98b4, cur);
        cur += 0x10;
    } while (cur < end);
    return (int)cur;
}

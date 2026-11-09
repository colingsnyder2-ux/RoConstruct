// from server: 88% by atomic.potato
typedef unsigned long DWORD;
typedef void* HWND;
typedef unsigned int UINT;
typedef unsigned long WPARAM;
typedef long LPARAM;
typedef int BOOL;

extern "C" void* __cdecl sub_007f3b1e();
extern "C" BOOL __stdcall PostMessageA(HWND, UINT, WPARAM, LPARAM);

struct ReportAbuseVerb
{
    int f();
};

int ReportAbuseVerb::f()
{
    void* a = sub_007f3b1e();
    void* b = *(void**)((char*)a + 4);
    HWND h = *(HWND*)((char*)b + 0x20);
    PostMessageA(h, 0x111, 0x8100, 0);
    return 0;
}

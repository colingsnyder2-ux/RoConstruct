// from server: 88% by atomic.potato
typedef unsigned int HWND;
typedef unsigned int UINT;
typedef unsigned int WPARAM;
typedef long LPARAM;
typedef int BOOL;

extern "C" void* sub_7a7c5e();
extern "C" BOOL __stdcall PostMessageA(HWND, UINT, WPARAM, LPARAM);

struct ReportAbuseVerb
{
    int f();
};

int ReportAbuseVerb::f()
{
    void* p = sub_7a7c5e();
    p = *(void**)((char*)p + 4);
    HWND h = *(HWND*)((char*)p + 0x20);
    PostMessageA(h, 0x111, 0x8100, 0);
    return 0;
}

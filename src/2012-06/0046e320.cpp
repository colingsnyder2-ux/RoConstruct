// from server: 71% by Intel
typedef int (__stdcall *GetPerformanceInfo_t)(void*, int);

extern "C" void* __stdcall LoadLibraryA(const char*);
extern "C" void* __stdcall GetProcAddress(void*, const char*);
extern "C" void __cdecl sub_9831f5(const char*);

int g_dwFlag = 0;
void* g_hPsapi = 0;
GetPerformanceInfo_t g_pGetPerformanceInfo = 0;

struct CBrowserDocManager {
    void method();
};

void CBrowserDocManager::method()
{
    if (g_dwFlag & 1)
        goto L_RETURN;

    g_dwFlag |= 1;
    g_hPsapi = 0;
    g_pGetPerformanceInfo = 0;

    g_hPsapi = LoadLibraryA("psapi.dll");
    if (g_hPsapi) {
        g_pGetPerformanceInfo = (GetPerformanceInfo_t)GetProcAddress(g_hPsapi, "GetPerformanceInfo");
    }

    sub_9831f5("twj8");

L_RETURN:
    if (!g_pGetPerformanceInfo)
        return;

    char buffer[0x38];
    int result = g_pGetPerformanceInfo(buffer, 0x38);
    if (!result)
        return;

    int* src = (int*)buffer;
    int* dst = (int*)0xE58BF0;
    for (int i = 0; i < 10; ++i) {
        dst[i] = src[i];
    }
}

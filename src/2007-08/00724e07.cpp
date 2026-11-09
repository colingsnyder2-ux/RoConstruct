// from server: 58% by Intel
struct OSVERSIONINFOA {
    unsigned long dwOSVersionInfoSize;
    unsigned long dwMajorVersion;
    unsigned long dwMinorVersion;
    unsigned long dwBuildNumber;
    unsigned long dwPlatformId;
    char szCSDVersion[128];
};

extern "C" int __stdcall GetVersionExA(OSVERSIONINFOA*);
extern "C" long __stdcall InterlockedExchange(long*, long);

void* g_pfnGetVersionExA = (void*)0x77D218;
void* g_pfnInterlockedExchange = (void*)0x77D248;
unsigned long g_dwCookie = 0x8B5188;
void* g_hModule = (void*)0x8BAB64;
const char* g_strSuccess = (const char*)0x724E03;
const char* g_strFailure = (const char*)0x724D9E;
void __cdecl __security_check_cookie(unsigned long);

struct CXTIconHandle {
    void CheckVersion();
};

void CXTIconHandle::CheckVersion() {
    OSVERSIONINFOA vi;
    unsigned long cookie = g_dwCookie ^ (unsigned long)&vi;
    vi.dwOSVersionInfoSize = 148;
    ((int (__stdcall*)(OSVERSIONINFOA*))g_pfnGetVersionExA)(&vi);
    const char* msg;
    if (vi.dwPlatformId == 2 && vi.dwMajorVersion >= 5) {
        msg = g_strSuccess;
    } else {
        msg = g_strFailure;
    }
    ((long (__stdcall*)(long*, long))g_pfnInterlockedExchange)((long*)g_hModule, (long)msg);
    ((void (__stdcall*)(void))g_hModule)();
    __security_check_cookie(cookie);
}

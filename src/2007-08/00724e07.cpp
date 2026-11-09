// from server: 49% by colin
struct OSVERSIONINFOA {
    unsigned long dwOSVersionInfoSize;
    unsigned long dwMajorVersion;
    unsigned long dwMinorVersion;
    unsigned long dwBuildNumber;
    unsigned long dwPlatformId;
    char szCSDVersion[128];
};

extern "C" int __stdcall GetVersionExA(OSVERSIONINFOA*);
extern "C" long __stdcall InterlockedExchange(long volatile*, long);

struct CXTIconHandle {
    void f();
};

void CXTIconHandle::f()
{
    OSVERSIONINFOA info;
    info.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&info);
    const char* p;
    if (info.dwMajorVersion == 2 && info.dwMinorVersion >= 5)
        p = (const char*)0x724e03;
    else
        p = (const char*)0x724d9e;
    InterlockedExchange((long volatile*)0x8bab64, (long)p);
}

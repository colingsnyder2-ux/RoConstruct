// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CRITICAL_SECTION_ { char data[24]; };
struct HWND__; typedef HWND__* HWND;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION_*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION_*);
extern "C" __declspec(dllimport) long __stdcall SendMessageW(HWND, unsigned int, unsigned int, long);
extern bool g_lockEnabled;
extern CRITICAL_SECTION_ g_cs;
struct ScopedLock {
    ScopedLock() { if (g_lockEnabled) EnterCriticalSection(&g_cs); }
    ~ScopedLock() { if (g_lockEnabled) LeaveCriticalSection(&g_cs); }
};
struct IUnk {
    virtual long __stdcall QueryInterface(const void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
struct Registry {
    IUnk* value;
    int a;
    int b;
    static Registry& instance();
};
HWND getWindow();
void stopAll(int);
IUnk* getRegistryValue();
void shutdown()
{
    HWND h = getWindow();
    if (h)
        SendMessageW(h, 0x10, 0, 0);
    stopAll(1);
    {
        Registry& r = Registry::instance();
        ScopedLock lock;
        r.b = 0;
    }
    IUnk* p = getRegistryValue();
    if (p)
        p->Release();
    {
        Registry& r = Registry::instance();
        ScopedLock lock;
        r.value = 0;
    }
}

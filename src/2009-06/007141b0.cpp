// from server: 100% by EspClaude
// roc 2009-06 007141b0
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CRITICAL_SECTION_ { char data[24]; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION_*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION_*);
extern bool g_lockEnabled;
extern CRITICAL_SECTION_ g_cs;
struct ScopedLock {
    ScopedLock() { if (g_lockEnabled) EnterCriticalSection(&g_cs); }
    ~ScopedLock() { if (g_lockEnabled) LeaveCriticalSection(&g_cs); }
};
struct Registry {
    void* value;
    Registry() throw();
    ~Registry();
};
void* getRegistryValue()
{
    static Registry s;
    ScopedLock lock;
    return s.value;
}

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CRITICAL_SECTION { void* a; long b, c; void* d, *e; unsigned long f; };
typedef struct HWND__* HWND;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
extern bool g_threaded;
extern CRITICAL_SECTION g_cs;
struct AutoLock {
    AutoLock() { if (g_threaded) EnterCriticalSection(&g_cs); }
    ~AutoLock() { if (g_threaded) LeaveCriticalSection(&g_cs); }
};
struct Doc {
    char pad[0x30];
    void* view;
    bool hasView() const { return view != 0; }
};
struct App {
    char pad[0xc];
    Doc* doc;
    char pad2[0x164 - 0x10];
    HWND mainWnd;
    HWND docWnd;
    Doc* getDoc() { AutoLock l; return doc; }
    HWND getMainWnd() { AutoLock l; return mainWnd; }
    HWND getDocWnd() { AutoLock l; return docWnd; }
};
App& getApp();
HWND getTopWindow()
{
    Doc* d = getApp().getDoc();
    if (d ? d->hasView() : false)
        return getApp().getDocWnd();
    return getApp().getMainWnd();
}

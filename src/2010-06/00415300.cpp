// from server: 0% by atomic.potato
// roc 2010-06 00415300  size: 406 bytes
// Minimal declarations for the clipboard/stringstream logic.

extern "C" {
    __declspec(dllimport) void* __stdcall GlobalLock(void* hMem);
    __declspec(dllimport) int __stdcall GlobalUnlock(void* hMem);
    __declspec(dllimport) void* __stdcall GetClipboardData(unsigned int uFormat);
    __declspec(dllimport) int __stdcall OpenClipboard(void* hWnd);
    __declspec(dllimport) int __stdcall CloseClipboard(void);
    __declspec(dllimport) unsigned int __stdcall RegisterClipboardFormatA(const char* lpString);
    __declspec(dllimport) void __stdcall EnterCriticalSection(void* lpCriticalSection);
    __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpCriticalSection);
}

// MSVCP90 string / istringstream helpers (symbolic declarations only).
struct StdString {
    char pad[0x1c];
};

struct StdIStringStream {
    char pad[0x80];
};

extern "C" {
    void __stdcall std_string_ctor(StdString* self, const char* s);
    void __stdcall std_string_dtor(StdString* self);
    void __stdcall std_istringstream_ctor(StdIStringStream* self, const StdString* s, int mode);
    void __stdcall std_istringstream_dtor(StdIStringStream* self);
}

// Internal helpers (symbolic).
void __stdcall sub_401910();
void __stdcall sub_414a70(void* p);
void __stdcall sub_4150f0(void* p);
void __stdcall sub_415270(void* p);
void* __stdcall sub_5f1b90(void* a, void* b);
void __stdcall sub_5f3080(void* a, void* b, void* c);
void* __stdcall sub_7a8156();

// Globals referenced.
extern void* g_9ebac4;
extern void* g_9ebca4;
extern void* g_9ebc9c;
extern void* g_9ea33c;
extern void* g_9ea410;
extern void* g_9ea428;
extern void* g_9ea400;
extern void* g_9ea340;
extern void* g_9ebca0;
extern void* g_9ea424;
extern void* g_9ea374;
extern void* g_9ea370;
extern unsigned int g_c00694;
extern void* g_c00690;
extern const char g_a02f00[];

struct VChangeHistoryService {
    void __stdcall FactoryProduct(void* arg);
};

void __stdcall VChangeHistoryService::FactoryProduct(void* arg)
{
    void* v;
    void* h;
    StdString str;
    StdIStringStream ss;
    void* local_94;
    void* local_8c;
    void* local_6c;
    void* local_68;
    void* local_64;
    void* local_70;

    v = sub_7a8156();
    if (v) {
        v = (*(void** (__stdcall**)(void*))(*(void***)v + 0x7c / 4))(v);
    } else {
        v = 0;
    }

    h = GlobalLock(*(void**)((char*)v + 0x20));
    if (!h) {
        return;
    }

    if (!(g_c00694 & 1)) {
        g_c00694 |= 1;
        g_c00690 = (void*)RegisterClipboardFormatA(g_a02f00);
    }

    local_70 = (void*)OpenClipboard(g_c00690);
    local_70 = (void*)GetClipboardData((unsigned int)local_70);
    std_string_ctor(&str, (const char*)local_70);

    std_istringstream_ctor(&ss, &str, 1);
    std_string_dtor(&str);

    sub_415270(&local_8c);
    local_64 = *(void**)sub_5f1b90(&local_6c, &local_8c);
    *(void**)sub_5f1b90(&local_6c, &local_8c) = 0;

    if (local_6c) {
        sub_4150f0(local_6c);
        sub_401910();
        EnterCriticalSection(0);
        LeaveCriticalSection(0);
    }

    sub_5f3080(&local_68, local_64, arg);

    if (local_64) {
        sub_4150f0(local_64);
        sub_401910();
        EnterCriticalSection(0);
        LeaveCriticalSection(0);
    }

    sub_414a70(&ss);
    GlobalUnlock(local_70);
    CloseClipboard();
    std_istringstream_dtor(&ss);
}

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CRITICAL_SECTION_ { char b[0x18]; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION_*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION_*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct FreeList {
    CRITICAL_SECTION_ cs;
    void* head;
};
FreeList* getFreeList();
extern long g_count;
void freeNode(void* p)
{
    FreeList* fl = getFreeList();
    EnterCriticalSection(&fl->cs);
    *(void**)p = fl->head;
    fl->head = p;
    LeaveCriticalSection(&fl->cs);
    InterlockedDecrement(&g_count);
}

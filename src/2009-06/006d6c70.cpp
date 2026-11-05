// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef long LONG;
struct CRITICAL_SECTION { void* a; long b, c; void* d, *e; unsigned long f; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) LONG __stdcall InterlockedDecrement(LONG volatile*);
struct Pool {
    CRITICAL_SECTION cs;
    void* head;
};
extern volatile LONG poolCount;
class Item {
public:
    static Pool* getPool();
    static void operator delete(void* p);
};
void Item::operator delete(void* p)
{
    Pool* pool = getPool();
    EnterCriticalSection(&pool->cs);
    *(void**)p = pool->head;
    pool->head = p;
    LeaveCriticalSection(&pool->cs);
    InterlockedDecrement(&poolCount);
}

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CRITICAL_SECTION { void* d; long a, b; void* c, *e; unsigned long f; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct Node { Node* next; };
struct Reg { CRITICAL_SECTION cs; Node* head; };
Reg* getReg();
extern long g_count;
void push(Node* n) { Reg* r = getReg(); EnterCriticalSection(&r->cs); n->next = r->head; r->head = n; LeaveCriticalSection(&r->cs); InterlockedDecrement(&g_count); }

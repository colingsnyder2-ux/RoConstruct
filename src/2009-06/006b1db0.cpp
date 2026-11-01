// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CritSec { void* a; long b; long c; void* d; void* e; unsigned long f; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CritSec*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CritSec*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct FreeNode { FreeNode* next; };
struct Pool { CritSec cs; FreeNode* head; };
extern Pool* __cdecl getPool();
extern long productCount;

struct Pooled
{
	static void operator delete(void* p)
	{
		Pool* pool = getPool();
		EnterCriticalSection(&pool->cs);
		FreeNode* node = static_cast<FreeNode*>(p);
		node->next = pool->head;
		pool->head = node;
		LeaveCriticalSection(&pool->cs);
		InterlockedDecrement(&productCount);
	}
};
class Item : public Pooled { public: Item(); virtual ~Item(); int x; };
Item::Item() {}

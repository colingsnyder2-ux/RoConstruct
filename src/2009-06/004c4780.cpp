// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* __stdcall GetProcessHeap();
extern "C" __declspec(dllimport) int __stdcall HeapFree(void*, unsigned long, void*);
#include <intrin.h>
struct Node {
	virtual ~Node();
	long refs;
};
struct NodePtr {
	Node* p;
	~NodePtr();
};
NodePtr::~NodePtr()
{
	Node* n = p;
	if (n) {
		if (_InterlockedDecrement(&n->refs) == 0) {
			n->~Node();
			HeapFree(GetProcessHeap(), 0, n);
		}
	}
}

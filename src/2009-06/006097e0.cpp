// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
struct Base {
	Base();
	virtual ~Base();
	char pad[0xd0];
};
struct Handle {
	long h;
	~Handle() { long old = _InterlockedExchange(&h, 0); if (old) CloseHandle((void*)old); }
};
struct Derived : Base {
	Handle event;
};
void make() { Derived* d = new Derived; delete d; }

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
struct SP { void* px; void* pn; SP() : px(0), pn(0) {} ~SP(); };
struct S {
	SP p;
	void* c;
	void* d;
	std::vector<int> v;
	int n;
	S();
};
S::S() : c(0), d(0), n(0) {}

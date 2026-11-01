// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct B1 { B1(); ~B1(); };
struct B2 { B2(); };
struct M : B2 { void* p; M(void* v); };
struct C : B1 {
	M m;
	int n;
	C(void* a, int b);
};
C::C(void* a, int b) : m(a), n(b) {}

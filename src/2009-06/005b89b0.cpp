// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct C {
	void* p; int n;
	~C();
	void reset(C r);
};
void swapC(C& a, C& b);
void C::reset(C r) { if (this != &r) swapC(*this, r); }

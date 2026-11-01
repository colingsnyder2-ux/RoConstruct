// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct SP { void* px; void* pn; SP() : px(0), pn(0) {} ~SP(); };
struct M { M(); ~M(); char pad[0x2c]; };
class C {
public:
	SP s;
	M m;
	bool flag;
	C();
};
C::C() : flag(false) {}

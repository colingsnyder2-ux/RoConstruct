// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern long g_count;
class B1 { public: virtual ~B1(); char pad[0x50]; };
class B2 { public: virtual void b2(); char pad[0x190 - 0x58]; };
class Base : public B1, public B2 { public: Base(); };
class Second { public: Second(); virtual void s0(); };
struct Counted {
	int d, a, b, c;
	Counted() : d(0) { InterlockedIncrement(&g_count); a = 0; b = 0; c = 0; }
};
class Derived : public Base, public Second {
public:
	Derived();
	virtual void s0();
	virtual void b2();
	int f0, f1, f2;
	Counted counted;
};
Derived::Derived() : f0(0), f1(0), f2(0) {}

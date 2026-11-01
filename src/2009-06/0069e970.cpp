// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class A;
class B { public: void onChild(A* a); };
class A { char pad[0x48]; B* parent; public: void f(int); };
void A::f(int) { parent->onChild(this); }

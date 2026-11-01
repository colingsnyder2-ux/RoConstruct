// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct P0 { virtual void p0(); char pad[0x14]; };
struct B18 { virtual void b0(); };
struct G { virtual void a(); virtual void b(); virtual void c(); virtual void d(B18* b, const int& v); };
extern G* g_obj;
class C : public P0, public B18 { public: void f(int v); };
void C::f(int v) { g_obj->d(this, v); }

// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { class Mouse { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void set(int a, bool b); };
class W { char pad[0x1cc]; public: Mouse m; };
class HammerTool { char pad[0x18]; W* w; public: void f(int a); };
void HammerTool::f(int a) { W* x = w; if (x) x->m.set(a, true); } }

// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { class L { public: virtual void v0(); virtual void v1(); virtual void on(int x); };
struct W { int a; L l; };
class Msg { public: void on(int x); };
class Workspace { char pad[0x1e8]; Msg m; char p2[0x210-0x1e9]; W* w; public: void f(int x); };
void Workspace::f(int x) { w->l.on(x); m.on(x); } }

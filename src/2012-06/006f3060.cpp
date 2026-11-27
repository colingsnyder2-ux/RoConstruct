// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Obj { char pad[0x148]; int field148; };
struct Sub { virtual void v0(); virtual Obj* getObj(); };
struct P { char pad[0x150]; Sub sub; };
struct S { int pad[3]; P* p; bool f(); };
bool S::f() { return p->sub.getObj()->field148 == 0; }

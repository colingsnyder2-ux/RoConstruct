// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Sub { bool a(); bool b(); };
struct S { char pad[0x80]; Sub s; bool f(); int g(); };
bool S::f() { return !s.a() && !s.b(); }

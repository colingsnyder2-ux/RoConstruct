// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct In { void cleanup(); };
struct N { char pad[0x18]; In in; };
struct H { int a; N* p; char c; bool own; void f(); };
void H::f() { if (p) { if (own) p->in.cleanup(); delete p; } }

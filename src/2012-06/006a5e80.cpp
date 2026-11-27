// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Y { void go(); };
extern void __cdecl fr(void*);
struct N { char pad[4]; Y* p; char pad2; bool b; void f(); };
void N::f() { if (p) { if (b) p->go(); fr(p); } }
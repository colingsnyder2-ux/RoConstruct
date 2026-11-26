// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct P { void m(int); };
P* __stdcall f(P* p) { p->m(0x3f); return p; }
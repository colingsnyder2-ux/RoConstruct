// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R { char pad[0x198]; int m; };
R* __stdcall G(int);
int f() { R* p = G(0); return p ? p->m : 0; }
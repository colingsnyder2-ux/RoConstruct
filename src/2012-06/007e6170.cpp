// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct X { char pad[0x9c]; int a; int pad2; int b; int* f(int* r); };
extern void __cdecl fn(int*, int*, int*);
int* X::f(int* r) { fn(r, &a, &b); return r; }
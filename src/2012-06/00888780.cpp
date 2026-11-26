// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct F { char p[0xac]; int a; int b; void g(); void f(int v); };
void F::f(int v) { if (v == a) { if (--b == 0) g(); } }
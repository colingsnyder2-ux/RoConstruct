// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char pad[0x188]; int v; void h(int); void m(int); };
void S::m(int a){ v=a; h(1); }


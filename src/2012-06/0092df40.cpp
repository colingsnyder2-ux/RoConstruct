// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
int __cdecl g(int); struct A{ char p[0x50]; int x; int f(int); };
int A::f(int){ return g(x); }

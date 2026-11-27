// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ int f(int); }; struct S: B{ char p[0x28]; int v; int f(int a); }; int S::f(int a){ if(a!=3) return B::f(a); return v; }

// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ int p[2]; int n; void g(); void f(); }; void S::f(){ if(n==0){ n=30; g(); return; } n=30; }

// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char p[0x10a]; bool flag; void g(); void f(int); }; void S::f(int){ if(flag) g(); }
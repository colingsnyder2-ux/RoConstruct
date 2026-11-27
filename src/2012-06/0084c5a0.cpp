// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct P{ short s[3]; }; void f(P* s,P* d){ if(d) *d=*s; }

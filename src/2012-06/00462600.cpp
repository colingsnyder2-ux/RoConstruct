// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
struct Q{ int g(int,int); }; struct A{ char p[0x80]; Q* q; int f(int a,int b){ if(q) return q->g(a,b); return 0; } }; int k(A*a){return a->f(1,2);}

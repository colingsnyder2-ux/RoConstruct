// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct A{char p[0x82]; short a; short b; void f(short x, short y){ a=x; b=y; } }; void g(A*p,short x,short y){p->f(x,y);}

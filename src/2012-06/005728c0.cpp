// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct S{char p[0x220]; char c;}; struct A{ char p[0x1a44]; S* s; char* f(){ char* q=&s->p[0x220-0]; *q=0; return q; } }; char* h(A*p){return p->f();}

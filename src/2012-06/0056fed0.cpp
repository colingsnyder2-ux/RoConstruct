// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct M{ unsigned short g(); }; struct A{ char p[0x1edc]; M m; int f(){ return m.g(); } }; int h(A*p){return p->f();}

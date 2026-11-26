// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct B; struct H{ int h(B*,int); }; struct B{ char p[0xbc]; H hh; int k(int); void f(int x){ int t=hh.h(this,x); k(t);} };  void g(B*b,int x){b->f(x);}

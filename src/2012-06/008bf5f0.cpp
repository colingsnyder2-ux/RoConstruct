// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct A { int a,b; }; struct B { int c; };
struct D : A, B { };
void g(B*);

void f(D *p){ g(static_cast<B*>(p)); }

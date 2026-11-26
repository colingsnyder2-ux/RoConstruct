// from server: 75% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void __stdcall g(int,int,int*,int*); struct X{ void f(int a,int b){ g(a,b,&a,&b); } }; void k(X*x,int a,int b){x->f(a,b);}

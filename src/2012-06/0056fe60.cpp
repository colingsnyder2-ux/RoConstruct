// from server: 78% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct T{int a,b;}; int __stdcall g(int,int,T*); struct X{ int f(int a,int b){ T t; T* p=&t; return g(a,b,p);} }; int k(X*x,int a,int b){return x->f(a,b);}

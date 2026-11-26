// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
int g(int,int,int); struct S{int pad; int a; int b; int f();}; int S::f(){ return g(a,-10000,b); }

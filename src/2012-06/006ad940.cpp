// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct T{char c; char p[3];}; void g(int,int,int,void*,int,T); struct S{ int f(int a,int b,int c); }; int S::f(int a,int b,volatile int c){ T t; t.c=0; g(a,b,c,this,c,t); return b*88+a; }

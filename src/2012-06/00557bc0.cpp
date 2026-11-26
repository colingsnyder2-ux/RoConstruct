// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct S{long g(int,unsigned,int); long f(int a,unsigned b,int c);}; long S::f(int a,unsigned b,int c){ if(b>0x7fffffff) return 0x80070057; return g(a,b,c);}

// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct A{ void g1(); void g2(int,int); void f(int a,int b){ g1(); g2(a,b);} }; void k(A*x){x->f(1,2);}

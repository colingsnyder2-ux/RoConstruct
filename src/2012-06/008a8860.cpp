// from server: 63% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct S; struct E{void g(S*,int);}; struct El{E* e;}; struct S{char pad[8]; El* arr; void f(int);}; void S::f(int i){ El& r=arr[i]; r.e->g(this,0); }

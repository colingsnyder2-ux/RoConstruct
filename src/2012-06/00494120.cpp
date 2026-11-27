// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct T { char pad[0x1e0]; int fl; void g(bool,int); void f(); };
void T::f(){ g(fl == 0, 1); }

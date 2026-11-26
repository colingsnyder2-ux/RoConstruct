// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct A{ float get(); }; void h(int,float);
void f(A* a,int x){ h(x,a->get());}

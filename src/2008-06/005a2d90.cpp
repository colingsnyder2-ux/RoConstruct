// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct B{void f(int);}; struct S{void g();};
void S::g(){char x=0; ((B*)((char*)this+188))->f(*(int*)&x);}

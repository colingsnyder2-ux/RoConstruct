// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct B{virtual void v0();virtual void v1();virtual void v2();}; struct S{char pad[0x8]; B* p; void f();};
void S::f(){p->v2();}

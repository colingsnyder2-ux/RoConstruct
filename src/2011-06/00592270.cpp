// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct I{virtual void f();}; struct S{char pad[0x20]; I* p; void g();};
void S::g(){p->f();}

// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef int (__thiscall *F)(void*,int,int); struct B{F fn; void* o; int a; int b;}; int f(B* p){ return p->fn(p->o,p->a,p->b); }

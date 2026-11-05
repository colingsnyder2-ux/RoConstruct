// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF- /GS- /EHsc /MT
typedef void (__thiscall *F)(void*,int,void*);
extern void* g;
struct V{void** v; void f(int);};
void V::f(int a){((F)v[207])(this,a,g);}

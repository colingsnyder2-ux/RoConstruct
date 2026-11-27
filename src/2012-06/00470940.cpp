// from server: 93% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
typedef void (__thiscall *F)(void*,void*,void*,void*); struct B{F fn; char* o; int adj; char a[0x1c]; char b[0x1c]; char c[8];}; void f(B** pp){ B* p=*pp; p->fn(p->o+p->adj, p->a, p->b, p->c); }

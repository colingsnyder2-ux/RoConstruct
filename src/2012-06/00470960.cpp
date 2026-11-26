// from server: 89% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
struct D{ void (__thiscall *fn)(void*,int); char* o; int adj; int arg; }; void f(D* d){ d->fn(d->o+d->adj, d->arg); }

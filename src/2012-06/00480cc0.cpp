// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ int (__thiscall *fn)(void*,int); void* o; };
int f(S* s,int a){ void* o=s->o; int (__thiscall *fn)(void*,int)=s->fn; return fn(o,a); }

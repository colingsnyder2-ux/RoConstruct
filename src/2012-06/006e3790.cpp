// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ void (__thiscall*fn)(void*,int*); int o; int adj; };
void f(S* s,int b){ s->fn((void*)(s->o+s->adj),&b); }


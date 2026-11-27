// from server: 71% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ void (__thiscall*fn)(void*,int); int o; int adj; };
void f(S* s,int b){ int a=s->adj; s->fn((void*)(s->o+a),b); }


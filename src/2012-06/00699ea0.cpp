// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S;
struct N { char pad[0x10]; S* s; };
struct S { char pad[0x8c]; void* a; void* b; void h(); void f(void*); };
struct M { void find(N** out, void** in); };
void S::f(void* arg) { N* l; ((M*)&a)->find(&l, &arg); if (l != b) l->s->h(); }
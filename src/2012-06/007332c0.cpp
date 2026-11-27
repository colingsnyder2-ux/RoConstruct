// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V { int g(V *const &); };
struct Desc;
typedef int (__thiscall *SetFn)(Desc *, int, int);
struct Vtbl { void *s0, *s1, *s2; SetFn set; };
struct Desc { Vtbl *vt; };
struct S { char pad[0x28]; Desc *desc; int f(int a, V *b); };
int S::f(int a, V *b){ Desc *p = desc; SetFn *fn = &p->vt->set; int value = b->g(b); return (*fn)(p, a, value); }

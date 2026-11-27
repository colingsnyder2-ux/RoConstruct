// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Tgt { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(void* a, int b); };
struct G { char pad[0x124]; Tgt* t; void f(char* x, int b); };
void G::f(char* x, int b) { t->v8(x ? x + 0x1c : 0, b); }

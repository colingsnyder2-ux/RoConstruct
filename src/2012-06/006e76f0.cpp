// from server: 75% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R { virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual bool get(int, int, int*); };
int k();
void reg(void*, void*);
extern int gg;
void cb();
bool f(R* r) { reg(&gg, (void*)cb); int x = k(); int v; if (!r->get(2, x, &v)) return false; *(int*)r = v; return true; }

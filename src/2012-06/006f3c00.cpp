// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct X { char pad[0x148]; int v; };
struct Sub { virtual void a(); virtual void b(); virtual X* c(); };
struct Ctx { char pad[0x150]; Sub sub; };
struct S { char pad[0xc]; Ctx* ctx; bool f(); };
bool S::f() { return ctx->sub.c()->v == 1; }

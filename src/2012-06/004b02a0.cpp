// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Ctl { virtual void v0(); virtual void v1(); virtual void v2(); virtual bool v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); };
struct VC { char pad[0x10c]; Ctl* c; void update(); };
void VC::update() { if (c->v3()) c->v8(); }

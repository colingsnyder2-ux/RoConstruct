// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V3{float x,y,z;};
struct Obj { char pad[0x24]; V3 v; void base(const Obj*); Obj* f(const Obj* p); };
Obj* Obj::f(const Obj* p) { base(p); v = p->v; return this; }

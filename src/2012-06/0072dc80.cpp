// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V3{float x,y,z;};
struct Obj { char pad[0x24]; V3 v; Obj(const Obj&); };
struct Acc { char pad[0xc0]; Obj o; void g(Obj* p); void f(const V3& p); };
void Acc::f(const V3& p) { Obj c(o); c.v = p; g(&c); }

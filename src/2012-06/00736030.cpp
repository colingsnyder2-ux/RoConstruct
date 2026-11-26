// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V{ float x,y,z; V(){} V(const V& o):x(o.x),y(o.y),z(o.z){} };
struct S{ char p[0x34]; V v; V f(); };
V S::f(){ return v; }

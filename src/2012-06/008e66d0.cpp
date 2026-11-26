// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V{ float x,y; V(){} V(const V& o):x(o.x),y(o.y){} };
struct S{ char p[0xd8]; V v; V f(); };
V S::f(){ return v; }

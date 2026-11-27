// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{unsigned short x,y,z; S f(const S& o) const;}; S S::f(const S& o) const { S r; r.x=x-o.x; r.y=y-o.y; r.z=z-o.z; return r; }

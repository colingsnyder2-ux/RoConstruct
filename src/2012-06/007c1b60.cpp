// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V3s { unsigned short x, y, z; V3s add(const V3s& o) const; };
V3s V3s::add(const V3s& o) const { V3s r; r.x = o.x + x; r.y = o.y + y; r.z = o.z + z; return r; }
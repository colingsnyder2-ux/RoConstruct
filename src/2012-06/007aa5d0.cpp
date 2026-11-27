// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V3{float x,y,z;}; struct K{char p[0xd4]; bool f; char p2[0x3]; V3 a; V3 b; V3 get() const;}; V3 K::get() const { return f ? a : b; }

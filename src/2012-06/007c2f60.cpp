// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R { int x; };
struct Other { const R& h() const; };
extern bool gFlag;
extern R gDefault;
struct S {
    char pad[0x84];
    int* vb;
    const R& g();
};
const R& S::g() { if (gFlag) return gDefault; return ((Other*)((char*)this + 0x84 + *vb))->h(); }
// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Other { void m(int); bool b() const; };
extern bool gFlag;
struct S {
    char pad[0x84];
    int* vb;    bool g();
};
bool S::g() { if (gFlag) return true; return ((Other*)((char*)this + 0x84 + *vb))->b(); }
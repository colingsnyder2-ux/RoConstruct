// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Other { void m(int); bool b() const; };
extern bool gFlag;
struct S {
    char pad[0x84];
    int* vb;    void f(int a);
};
void S::f(int a) { if (!gFlag) ((Other*)((char*)this + 0x84 + *vb))->m(a); }
// from server: 88% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct P0 { virtual void f0(); };
struct P1 { virtual void f1(); int pad[4]; };
struct P2 { virtual void f2(); };
struct P3 { virtual void f3(); int pad[2]; };
struct Base : P0, P1, P2, P3 { Base(); ~Base(); };
struct P4 { int f28; char pad[0x7c]; int a8; P4(int a) : a8(a) {} };
void* make();
static int g_count;
struct D : Base, P4 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    D(int a);
};
D::D(int a) : Base(), P4(a) { f28 = (int)make(); ++g_count; }

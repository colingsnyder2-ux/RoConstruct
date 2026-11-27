// from server: 84% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct B0 { virtual void a(); ~B0(); };
struct B1 { virtual void b(); int p[4]; };
struct B2 { virtual void c(); };
struct B3 { virtual void d(); };
struct D : B0, B1, B2, B3 { virtual void a(); virtual void b(); virtual void c(); virtual void d(); ~D(); };
D::~D() {}
extern char gobj[0x20];
void h(void*);
void thunk() { h(gobj); }

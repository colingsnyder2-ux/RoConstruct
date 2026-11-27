// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct B1 { B1(); virtual void f0(); };
struct __declspec(novtable) B2 { virtual void g0() = 0; };
struct __declspec(novtable) B3 { virtual void h0() = 0; int x; };
struct __declspec(novtable) B4 { virtual void i0() = 0; int y; };
struct __declspec(novtable) B5 { virtual void j0() = 0; };
struct Svc { virtual void q0(); virtual void addRef(); };
extern Svc* g_svc;
struct D : B1, B2, B3, B4, B5 {
    D(int);
    virtual void f0(); virtual void g0(); virtual void h0(); virtual void i0(); virtual void j0();
};
D::D(int) { g_svc->addRef(); }

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct X { virtual void f(); };
struct Y { virtual void g(); };
struct B : X, Y { B(int a, int b); char pad[0x44 - 8]; };
struct D : B {
    float c, d;
    D(int a, int b, float c, float d);
    virtual void f();
    virtual void g();
};
D::D(int a, int b, float c_, float d_) : B(a, b), c(c_), d(d_) {}

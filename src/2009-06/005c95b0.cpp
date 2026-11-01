// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct A { virtual ~A(); char pad[0x10]; };
struct B { virtual void b(); };
struct C { virtual void c(); int pad; };
struct D { virtual void d(); };
struct Base : A, B, C, D { virtual ~Base(); };
struct X : Base {
    X();
    virtual ~X() {}
    virtual void b();
    virtual void c();
    virtual void d();
};
X::X() {}

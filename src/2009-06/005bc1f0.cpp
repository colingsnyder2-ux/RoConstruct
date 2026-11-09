// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct X;
struct Base { Base(const X& x); int a, b; };
struct S { int v[5]; };
struct C : Base {
    S s;
    C(const X& x, const S& s);
};
C::C(const X& x, const S& s_) : Base(x), s(s_) {}

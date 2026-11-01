// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct B { int x; B(); };
struct S { bool x; };
struct A : B { S v; A(const S& o); };
A::A(const S& o) : v(o) {}

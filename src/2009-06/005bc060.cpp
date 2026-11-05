// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct B { B(); };
struct S { int x; };
struct A : B { S v; A(const A& o); };
A::A(const A& o) : v(o.v) {}

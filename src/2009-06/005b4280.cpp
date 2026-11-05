// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /EHsc /MT
struct A { A(); };
struct Base { Base(); ~Base(); int x[3]; };
struct V : Base { V(unsigned n); void init(unsigned n, const A& a); };
V::V(unsigned n) { init(n, A()); }

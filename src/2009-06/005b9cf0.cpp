// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /EHsc /MT
struct P { int v; };
struct Base { Base(); ~Base(); int x; };
struct V : Base { P m4; V(unsigned n, const P& v); void f(unsigned n); };
V::V(unsigned n, const P& v) { f(n); m4 = v; }

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct B { B(); ~B(); };
struct D : B { D(const D& o); void init(const D& o); };
D::D(const D& o) { init(o); }

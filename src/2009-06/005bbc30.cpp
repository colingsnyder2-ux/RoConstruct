// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct B { int a, b; ~B(); };
struct M { ~M(); };
struct D : B { M m; ~D(); };
D::~D() {}

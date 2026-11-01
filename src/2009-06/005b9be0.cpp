// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct B { ~B(); };
struct M { ~M(); };
struct D : B { M m; ~D(); };
D::~D() {}

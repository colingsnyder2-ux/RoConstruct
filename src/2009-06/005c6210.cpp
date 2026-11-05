// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct B { ~B(); };
struct D : B { void tidy(); ~D(); };
D::~D() { tidy(); }

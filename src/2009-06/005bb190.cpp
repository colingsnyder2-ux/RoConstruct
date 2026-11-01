// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
struct TagA {}; struct TagD : TagA {}; struct TagB {};
struct M; struct E;
void g(M& m, const E& e, TagA, TagB);
void f(M& m, const E& e) { g(m, e, TagD(), TagB()); }

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct Tag {};
void g(int* a, int* b, Tag t);
void f(int* a, int* b) { g(a, b, Tag()); }

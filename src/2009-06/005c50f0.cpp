// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct S { S(int a, int b); void init(int a, int b); };
S::S(int a, int b) { init(a, b); }

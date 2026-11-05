// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /EHsc /MT
struct Src { int get(int i); };
struct R { R(int v); R(const R& o); ~R(); int x; };
R make(Src& s, int i) { return R(s.get(i)); }

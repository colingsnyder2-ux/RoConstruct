// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /EHsc /MT
struct R { R(int); R(const R&); ~R(); int v; };
R make(int a) { return R(a); }

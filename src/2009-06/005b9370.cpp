// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /EHsc /MT
struct Inner;
struct Arg { const Inner& get() const; };
struct R { R(const Inner& a, const Inner& b); ~R(); int x[4]; };
R f(const Arg& a, const Arg& b) { return R(a.get(), b.get()); }

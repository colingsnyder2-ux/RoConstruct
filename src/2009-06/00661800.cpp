// from server: 81% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct F { F(const F&); ~F(); char d[0x28]; };
struct R { ~R(); int x; };
struct Impl { R f(int a, F fn); };
struct C { Impl* get(); R f(int a, F fn); };
R C::f(int a, F fn) { return get()->f(a, fn); }

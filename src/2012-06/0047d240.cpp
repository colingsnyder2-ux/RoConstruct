// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R { char b[28]; };
struct O { R h(int v); };
struct S { int v; R g(int, O* o, int, int) const; };
R S::g(int, O* o, int, int) const { volatile int z = 0; return o->h(v); }
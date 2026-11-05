// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /EHsc /MD
struct T1 {};
struct T2 {};
struct It { int* p; };
struct R { int* a; int* b; R(); R(const R&); ~R(); };
R g(It a, It b, T1, T2);
R f(It a, It b) { return g(a, b, T1(), T2()); }

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT /EHsc
struct R { ~R(); int x, y; };
struct T { R g(int a, int b, int c); };
struct H { T* p; T* get(); R f(int a, int b, int c); };
R H::f(int a, int b, int c) { return get()->g(a, b, c); }

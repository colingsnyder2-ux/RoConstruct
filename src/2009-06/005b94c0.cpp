// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT /EHsc
struct A { A& self(); };
struct R { R(A&, A&); ~R(); int x, y; };
R mk(A& a, A& b) { return R(a.self(), b.self()); }

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /EHsc /MT
struct E { ~E(); };
struct M { ~M(); int x; };
struct S : E { M a; M b; ~S(); };
S::~S() {}

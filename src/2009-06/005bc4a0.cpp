// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
const int& g1(const int& a, const int& b);
const int& g2(const int& a, const int& b);
int clampIt(int a, int b, int c) { return g2(b, g1(c, a)); }

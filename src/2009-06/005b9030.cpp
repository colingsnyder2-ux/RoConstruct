// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct A { int pad; int n; double* data; double* end(); };
double* A::end() { return data + n; }

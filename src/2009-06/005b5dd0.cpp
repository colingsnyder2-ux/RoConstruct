// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct A { char p[0x44]; float x; float f() const; };
float A::f() const { return x; }

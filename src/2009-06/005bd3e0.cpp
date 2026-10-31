// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct A { char p[0x41]; char x; char f() const; };
char A::f() const { return x; }

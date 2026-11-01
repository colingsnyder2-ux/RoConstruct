// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Base { Base(int a, int b, int c); virtual void v0(); char pad[0x64]; };
struct D : Base { D(int a, int b); virtual void v0(); float f; };
D::D(int a, int b) : Base(a, b, 0), f(0) {}

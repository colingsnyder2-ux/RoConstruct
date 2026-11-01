// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Obj { void update(); };
struct A { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10();
  char p[0x18]; Obj* obj; char p2[8]; bool flag; char p3[0x37-0x29]; };
struct B { virtual int b0(); };
struct D : A, B { virtual int b0(); };
int D::b0() { obj->update(); flag = false; a10(); return 0; }

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
class C { int x; };
struct Call { void (C::*fn)(int, int, int); C* obj; int a, b, c; };
void invoke(const Call& c) { (c.obj->*c.fn)(c.a, c.b, c.c); }

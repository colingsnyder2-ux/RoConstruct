// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Vector2 { float x, y; Vector2(const Vector2& o) : x(o.x), y(o.y) {} };
struct S { void g(int n, Vector2 v); void f(Vector2 v); };
void S::f(Vector2 v) { g(3, v); }

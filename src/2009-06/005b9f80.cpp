// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct Tag {};
struct C { void callee(int); void f(); };
void C::f()
{
    bool t;
    callee(t);
}

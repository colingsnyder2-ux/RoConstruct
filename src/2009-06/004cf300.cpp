// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct M { void f(); };
struct S {
    char pad[0x20];
    M m;
    void g();
};
void S::g()
{
    int a, b, c, d, e;
    m.f();
}

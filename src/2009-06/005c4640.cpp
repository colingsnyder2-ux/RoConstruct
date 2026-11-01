// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct It { It(); int a, b; };
struct Val { Val(It p); int x, y; };
struct Vec { void resize(unsigned n, const Val& v); };
struct C {
    char pad[0x24]; Vec v; char pad2[0x17]; int m3c; int m40;
    It first();
    void f(int n);
};
void C::f(int n) { Val val(first()); v.resize(n + 1, val); m3c = n - 1; m40 = n; }

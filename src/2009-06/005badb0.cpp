// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct B { B(int a); int x; int y; };
struct V { float x, y, z; };
struct D {
    B b;
    V v;
    D(int a, const V& v);
};
D::D(int a, const V& v) : b(a), v(v) {}

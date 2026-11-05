// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct R { int x; R(int v); };
struct S {
    int get(int a);
    R f(int a);
};
R S::f(int a)
{
    return R(get(a));
}

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct Inner { int h(int v); };
struct S {
    int a, b;
    Inner in;
    int g(int n);
    int f(int v);
};
int S::f(int v)
{
    return g(in.h(v));
}

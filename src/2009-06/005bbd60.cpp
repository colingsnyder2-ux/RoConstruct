// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
int combine(int a, int b);
struct Inner { int get(int v); };
struct S {
    int a, b, c, d;
    Inner in;
    int lookup(int v);
    int f(int x, int y);
};
int S::f(int x, int y)
{
    return combine(lookup(x), in.get(y));
}

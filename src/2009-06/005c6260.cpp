// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct V { int a, b, c; };
struct Inner { int x; };
struct Q { V make(Inner* in); };
struct Outer {
    int a, b;
    Inner in;
    V get(Q* q);
};
V Outer::get(Q* q)
{
    return q->make(&in);
}

// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct P
{
    char pad0[0x94];
    unsigned char n : 4;
    unsigned char m : 4;
    char pad1[0x80];
    bool locked;
};
struct Inner { void g(P *, P *); };
struct S
{
    char pad0[8];
    Inner inner;
    void f(P *a, P *b);
};
void S::f(P *a, P *b)
{
    if (!a->locked) a->n++;
    if (!b->locked) b->n++;
    inner.g(a, b);
}
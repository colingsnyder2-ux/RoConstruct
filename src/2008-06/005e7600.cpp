// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct S;
struct P {
    void g(S*);
};

struct S {
    char pad0[88];
    P* p;
    char pad1[84];
    float value;
    void f(float v);
};

void S::f(float v)
{
    if (v != value) {
        value = v;
        if (p)
            p->g(this);
    }
}

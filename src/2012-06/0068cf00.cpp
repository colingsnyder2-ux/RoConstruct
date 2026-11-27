// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct CF { char b[0x30]; };
struct Tgt { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual bool v8(float a, CF* p, CF* q); };
struct Cam {
    char pad[0x88]; CF f88; CF fb8; char pad2[0x148 - 0xe8]; int mode; int flag;
    Tgt* getTarget(); bool g(float a); bool h(float a);
    bool f(float a);
};
bool Cam::f(float a)
{
    int m = mode;
    if (m == 5) {
        Tgt* t = getTarget();
        if (t) return t->v8(a, &f88, &fb8);
        return false;
    }
    if (flag != 0 && (m == 4 || m == 1 || m == 3)) return g(a);
    return h(a);
}

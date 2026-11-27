// from server: 96% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Before { virtual ~Before(); char p[0x18]; };
struct DescribedBase { virtual ~DescribedBase(); };
struct Mid { char p[0x64]; };
struct V { int x; };
struct Cls : Before, DescribedBase, Mid, virtual V { int get(); };
struct S {
    char pad[0x30]; int (Cls::*fn)();
    int f(DescribedBase* obj, int q);
};
int S::f(DescribedBase* obj, int q){ Cls* c = static_cast<Cls*>(obj); int (Cls::*g)() = fn; return (c->*g)(); }

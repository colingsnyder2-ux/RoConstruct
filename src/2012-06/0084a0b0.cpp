// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Inner { char d[0x24]; Inner(const Inner&); ~Inner(); };
struct Mid { Inner in; Mid(const Inner& i) : in(i) {} }; struct Obj { int a; Mid m; Obj(int a_, const Inner& i) : a(a_), m(i) {} };
struct Impl {
    Impl(int a1, Inner in, int a10);
    void init(Obj o, int z);
};
Impl::Impl(int a1, Inner in, int a10)
{
    init(Obj(a1, in), 0);
}

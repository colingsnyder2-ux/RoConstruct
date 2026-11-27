// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

union Buf { double align; char data[0x18]; };
struct VT { void (*manager)(const Buf& in, Buf& out, int op); };
struct Fn {
    VT* vtable;
    mutable Buf functor;
    Fn(const Fn& f) : vtable(0)
    {
        if (f.vtable) {
            vtable = f.vtable;
            f.vtable->manager(f.functor, functor, 0);
        }
    }
    ~Fn()
    {
        if (vtable) {
            void (*m)(const Buf&, Buf&, int) = vtable->manager;
            if (m) m(functor, functor, 2);
        }
    }
};
struct R {
    R(void* x, Fn f);
    void init(void* x, Fn f);
};
R::R(void* x, Fn f)
{
    init(x, f);
}

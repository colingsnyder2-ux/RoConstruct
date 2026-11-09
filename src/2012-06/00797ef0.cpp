// from server: 94% by tajop

union fbuf_00797ef0 {
    void* obj;
    double align;
    char data[16];
};
struct fvtbl_00797ef0 {
    void (*manager)(const fbuf_00797ef0& in, fbuf_00797ef0& out, int op);
};
struct function_00797ef0 {
    fvtbl_00797ef0* vtable;
    fbuf_00797ef0 functor;
    function_00797ef0(const function_00797ef0& f) : vtable(0)
    {
        if (f.vtable) {
            vtable = f.vtable;
            f.vtable->manager(f.functor, functor, 0);
        }
    }
    ~function_00797ef0();
};
struct slotbase_00797ef0 {
    virtual void a();
    int x;
    slotbase_00797ef0() {}
};
struct conn0_00797ef0 {
    virtual ~conn0_00797ef0();
    int n;
    conn0_00797ef0() : n(0) {}
};
struct conn_00797ef0 : conn0_00797ef0 {
    void* sig;
    conn_00797ef0(void* s) : sig(s) {}
    virtual ~conn_00797ef0();
};
struct callable_00797ef0 : slotbase_00797ef0, conn_00797ef0 {
    function_00797ef0 func;
    callable_00797ef0(const function_00797ef0& f, void* s);
    virtual void a();
};
callable_00797ef0::callable_00797ef0(const function_00797ef0& f, void* s)
    : conn_00797ef0(s), func(f)
{
}

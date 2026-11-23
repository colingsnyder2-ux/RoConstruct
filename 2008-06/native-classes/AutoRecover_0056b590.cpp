// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the function is boost::detail::shared_count::shared_count(P p) for an
// EnumDesc<CRenderSettings::GraphicsMode>-style item. It allocates a 16-byte
// sp_counted_impl_p with use_count=1, weak_count=1 and the pointer. If the
// allocation throws, the catch handler calls EnumDesc::deleteItem(p) and rethrows.

extern "C" void* fn_006a0920(int size);          // operator new
extern "C" void fn_00427b70(const void* item);   // EnumDesc<GraphicsMode>::deleteItem

struct sp_counted_base_impl
{
    // INFERRED: vtable at 0x82f614 (dispose/destroy)
    virtual void dispose() {}
    virtual void destroy() {}
    int use_count_;
    int weak_count_;
    void* ptr_;

    explicit sp_counted_base_impl(void* p) : use_count_(1), weak_count_(1), ptr_(p) {}

    // class-local placement new (avoids needing <new>)
    static void* operator new(unsigned int, void* where) { return where; }
};

struct SharedCountHolder
{
    sp_counted_base_impl* pi_;
};

extern "C" SharedCountHolder* __fastcall fn_0056b590(SharedCountHolder* self, int unusedEdx, void* p)
{
    self->pi_ = 0;
    try
    {
        void* mem = fn_006a0920(0x10);
        sp_counted_base_impl* impl = 0;
        if (mem)
            impl = new (mem) sp_counted_base_impl(p);
        self->pi_ = impl;
    }
    catch (...)
    {
        fn_00427b70(p);
        throw;
    }
    return self;
}

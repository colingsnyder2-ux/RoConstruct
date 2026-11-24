// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is boost::detail::shared_count::shared_count(worker_thread::data* p),
// i.e. the constructor of shared_ptr<RBX::worker_thread::data> from a raw pointer.

namespace RBX { namespace worker_thread { struct data; } }

// INFERRED: func_006a0920 is operator new(size_t); the callee list shows 9 args,
// but the disassembly pushes only one.
extern "C" void* fn_006a0920(unsigned size);

// checked_delete<RBX::worker_thread::data>
extern "C" void fn_00595c50(RBX::worker_thread::data* p);

namespace {

struct sp_counted_base {
    int use_count_;
    int weak_count_;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    virtual ~sp_counted_base() {}
    static void* operator new(unsigned size) { return fn_006a0920(size); }
    sp_counted_base() : use_count_(1), weak_count_(1) {}
};

struct sp_counted_impl_p : sp_counted_base {
    RBX::worker_thread::data* ptr_;
    explicit sp_counted_impl_p(RBX::worker_thread::data* p) : ptr_(p) {}
    virtual void dispose() {}
    virtual void destroy() {}
};

struct shared_count_like {
    sp_counted_base* pi_;
};

}

extern "C" shared_count_like* __fastcall fn_00596110(shared_count_like* self, int unusedEdx, RBX::worker_thread::data* p)
{
    self->pi_ = 0;
    try {
        self->pi_ = new sp_counted_impl_p(p);
    } catch (...) {
        fn_00595c50(p);
        throw;
    }
    return self;
}

// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <new>

// INFERRED: this is boost::shared_count::shared_count(Instance* p, Creatable<Instance>::Deleter d).
// It allocates a 0x14-byte sp_counted_impl_pd (vtable, use=1, weak=1, px, empty deleter).
// If the allocation or construction throws, it calls d(p) and rethrows.

namespace RBX {
    class Instance;
    template<class T> struct Creatable {
        struct Deleter {
            void operator()(Instance* p);
        };
    };
}

// INFERRED: the callee is really an operator-new style allocator taking only the size
// (the disassembly pushes a single argument, 0x14, and pops 4 bytes).
extern "C" void* fn_006a0920(int size);

typedef RBX::Creatable<RBX::Instance>::Deleter InstDeleter;

// INFERRED: counted-base layout with vtable at 0x80b3f8
struct sp_counted_base_local {
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    virtual void* get_deleter() = 0;
    int use_count_;
    int weak_count_;
};

struct sp_counted_impl_pd_local : public sp_counted_base_local {
    RBX::Instance* ptr_;
    InstDeleter del_;

    sp_counted_impl_pd_local(RBX::Instance* p, InstDeleter d)
        : ptr_(p), del_(d)
    {
        use_count_ = 1;
        weak_count_ = 1;
    }
    virtual void dispose() { del_(ptr_); }
    virtual void destroy() { delete this; }
    virtual void* get_deleter() { return 0; }
};

struct shared_count_local {
    sp_counted_base_local* pi_;
};

extern "C" shared_count_local* __fastcall fn_00406ed0(shared_count_local* self, int unusedEdx,
                                                      RBX::Instance* p, InstDeleter d)
{
    self->pi_ = 0;
    try {
        void* mem = fn_006a0920(0x14);
        sp_counted_impl_pd_local* obj = 0;
        if (mem)
            obj = new (mem) sp_counted_impl_pd_local(p, d);
        self->pi_ = obj;
    } catch (...) {
        d(p);
        throw;
    }
    return self;
}

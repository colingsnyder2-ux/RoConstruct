// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: shared_count ctor from (pointer, deleter), as boost sp_counted_impl_pd; the catch calls deleter(p) and rethrows.
struct Instance;
struct Deleter {
    void operator()(Instance* p) const;
};

struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    int use_count;
    int weak_count;
};

// INFERRED: vtable comes from this real class instead of a hardcoded address.
struct sp_counted_impl : sp_counted_base {
    Instance* ptr;
    sp_counted_impl(Instance* p) : ptr(p) { use_count = 1; weak_count = 1; }
    virtual void dispose() { Deleter()(ptr); }
};

extern "C" void* fn_006a0920(int size);

struct shared_count {
    sp_counted_base* pi;
};

extern "C" shared_count* __fastcall fn_00456410(shared_count* self, int unusedEdx, Instance* p, Deleter d)
{
    self->pi = 0;
    try {
        void* mem = fn_006a0920(0x14);
        sp_counted_base* b = 0;
        if (mem)
            b = new (mem) sp_counted_impl(p);
        self->pi = b;
    } catch (...) {
        d(p);
        throw;
    }
    return self;
}

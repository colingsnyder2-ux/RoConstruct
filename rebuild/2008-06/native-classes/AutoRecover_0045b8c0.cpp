// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is boost::shared_count::shared_count(Instance* p, Creatable<Instance>::Deleter d).
// It allocates an sp_counted_impl_pd block (0x14 bytes: vtable, use_count, weak_count, ptr, deleter).
// On exception it runs the deleter on p and rethrows.

namespace RBX {
    class Instance;
}

struct DeleterStub {
    // INFERRED: empty functor passed by value (occupies one stack dword)
    char pad;
};

struct SharedCountStub {
    void* pi_;
};

struct CountedImplStub {
    const void* const* vtbl;
    int use_count;
    int weak_count;
    RBX::Instance* ptr;
    // deleter is empty; block size is 0x14 (padded by the allocator call)
};

// INFERRED: callee is operator new(0x14); the disassembly shows a single pushed argument.
extern "C" void* fn_006a0920(int size);

// vtable of sp_counted_impl_pd<Instance*, Creatable<Instance>::Deleter>
// INFERRED: unknown global, declared as an array so its address is the vtable pointer.
extern "C" const void* const g_0081987c[];

// RBX::Creatable<RBX::Instance>::Deleter::operator()(Instance*)
extern "C" void __fastcall fn_00405e30(DeleterStub* self, int unusedEdx, RBX::Instance* p);

extern "C" SharedCountStub* __fastcall fn_0045b8c0(SharedCountStub* self, int unusedEdx,
                                                   RBX::Instance* p, DeleterStub d)
{
    self->pi_ = 0;
    try {
        CountedImplStub* impl = (CountedImplStub*)fn_006a0920(0x14);
        if (impl) {
            impl->use_count = 1;
            impl->weak_count = 1;
            impl->vtbl = g_0081987c;
            impl->ptr = p;
        }
        self->pi_ = impl;
    }
    catch (...) {
        fn_00405e30(&d, 0, p);
        throw;
    }
    return self;
}

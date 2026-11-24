// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: boost::shared_ptr<T> ctor(T* p): sp_counted_base_impl<T*, checked_deleter<T>> with use=1, weak=1, ptr at +0xc.
extern "C" void* fn_006a0920(unsigned size); // operator new, cdecl (only 1 arg is actually used)

struct CountedBase {
    int use;
    int weak;
    void* ptr;
    virtual ~CountedBase() {}
    virtual void dispose() {}
    virtual void destroy() {}
};

struct SharedPtrHolder {
    CountedBase* pn;
};

extern "C" SharedPtrHolder* __fastcall fn_0041ae30(SharedPtrHolder* self, int unusedEdx, void* p)
{
    self->pn = 0;
    CountedBase* c = (CountedBase*)fn_006a0920(0x10);
    if (c) {
        c->use = 1;
        c->weak = 1;
        c->ptr = p;
    }
    self->pn = c;
    return self;
}

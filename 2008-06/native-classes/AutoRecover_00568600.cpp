// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: shared_ptr-style control block (vtable, use count, weak count, ptr) built from
// the allocation size 0x14, the two counts set to 1, and the pointer taken from arg1.
// INFERRED: arg2 is the empty Creatable<Instance>::Deleter, passed by value and unused here.
extern "C" void* fn_006a0920(unsigned int size);

struct SpCountedDeleter {
    virtual void dispose();
    int useCount;
    int weakCount;
    void* ptr;
    SpCountedDeleter(void* p) : useCount(1), weakCount(1), ptr(p) {}
    void* operator new(unsigned int size) { return fn_006a0920(size); }
};

struct DeleterTag { };

struct SharedHolder {
    SpCountedDeleter* pn;
    SharedHolder(void* p, DeleterTag d) {
        pn = 0;
        pn = new SpCountedDeleter(p);
    }
};

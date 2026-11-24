// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: minimal local reconstruction of boost::any::holder<boost::function<void(shared_ptr<Instance>)>>
// layout: holder { vptr@0, held@8 { vtable@0, functor buffer@8 (8-aligned) } }.

struct FnBuffer {
    union {
        void* obj_ptr;
        char data[16];
        long long align_;
    };
};

struct FnVTable {
    void (*manager)(const FnBuffer* in, FnBuffer* out, int op);
    void* invoker;
};

// INFERRED: single function object with a destructor gives the single EH state (0) seen in the original
struct Function1 {
    FnVTable* vtable;
    FnBuffer functor;

    __forceinline Function1(const Function1& f) : vtable(0)
    {
        if (f.vtable) {
            vtable = f.vtable;
            f.vtable->manager(&f.functor, &functor, 0); // clone_functor_tag
        }
    }
    __forceinline ~Function1()
    {
        if (vtable) {
            vtable->manager(&functor, &functor, 2); // destroy_functor_tag
            vtable = 0;
        }
    }
};

struct Holder {
    Function1 held;
    // INFERRED: a virtual member provides the vptr without registering a base-destructor unwind state
    virtual void dummy() {}
    __forceinline Holder(const Function1& f) : held(f) {}

    // INFERRED: class-specific placement new so the object is built in place (no delete cleanup state)
    static void* operator new(unsigned int, void* p) { return p; }
};

extern "C" Holder* __fastcall fn_004d7a10(Holder* self, int unusedEdx, const Function1* f)
{
    // INFERRED: original is a real constructor, so no null check on 'this'
    __assume(self != 0);
    return new (self) Holder(*f);
}

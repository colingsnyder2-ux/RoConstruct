// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers were provided, so boost::function / boost::any::holder are mimicked with
// minimal file-local layouts. They reproduce the offsets the disassembly shows: vptr at +0,
// function vtable pointer at +8, function_buffer at +0x10.
#include <new>

namespace {

union function_buffer {
    void* obj_ptr;
    char data[16];
    double align_dummy; // forces 8-byte alignment, so the held function sits at holder+8
};

struct vtable_base {
    void (__cdecl *manager)(const function_buffer& in, function_buffer& out, int op);
};

struct function_t {
    vtable_base* vtable;
    function_buffer functor;

    function_t() : vtable(0) {}
    function_t(const function_t& f) : vtable(0) {
        if (f.vtable) {
            vtable = f.vtable;
            f.vtable->manager(f.functor, functor, 0); // clone_functor_tag
        }
    }
    ~function_t() { clear(); }
    void clear() {
        if (vtable) {
            vtable->manager(functor, functor, 2); // destroy_functor_tag
            vtable = 0;
        }
    }
};

struct placeholder {
    virtual ~placeholder() {}
    virtual placeholder* clone() const = 0;
};

struct holder : placeholder {
    // INFERRED: class-specific placement new without throw(), so no null check is emitted
    // and the constructor is entered directly on the passed 'this'.
    static void* operator new(size_t, void* p) { return p; }
    static void operator delete(void*, void*) {}
    static void* operator new(size_t n) { return ::operator new(n); }
    static void operator delete(void* p) { ::operator delete(p); }

    holder(const function_t& value) : held(value) {}
    virtual placeholder* clone() const { return ::new holder(held); }
    function_t held;
};

} // namespace

extern "C" holder* __fastcall fn_0049f5b0(holder* self, int unusedEdx, const function_t* value)
{
    return new (self) holder(*value);
}

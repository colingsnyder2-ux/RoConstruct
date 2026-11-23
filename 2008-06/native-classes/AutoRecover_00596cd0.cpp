// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>
#include <new>

// INFERRED: this is a boost::function functor manager for a bind_t object
// (0x50 bytes) that holds a function0<void> at offset 8.
struct function_buffer {
    union {
        void* obj_ptr;
        const std::type_info* type;
    };
};

// INFERRED: operator new wrapper; the call site passes a single size argument.
extern "C" int fn_006a0920(int size);
// INFERRED: copy constructor of the bound functor (dest, src).
extern "C" int fn_00596a50(int dest, int src);
// INFERRED: storage2<value<function0<void>>> destructor (thiscall).
extern "C" void __fastcall fn_00596470(void* self, int unusedEdx);

// INFERRED: the original compares against the type_info object at 0x949af8;
// a local functor type stands in for it here.
struct bound_functor_t { char pad[0x50]; };

extern "C" void fn_00596cd0(const function_buffer* in_buffer, function_buffer* out_buffer, int op)
{
    if (op == 0) {
        // clone
        void* src = in_buffer->obj_ptr;
        int mem = fn_006a0920(0x50);
        fn_00596a50(mem, (int)src);
        out_buffer->obj_ptr = (void*)mem;
        return;
    }
    if (op == 1) {
        // destroy
        char* p = (char*)out_buffer->obj_ptr;
        fn_00596470(p + 8, 0);
        ::operator delete(p);
        out_buffer->obj_ptr = 0;
        return;
    }
    // check type
    if (*out_buffer->type == typeid(bound_functor_t)) {
        out_buffer->obj_ptr = in_buffer->obj_ptr;
    } else {
        out_buffer->obj_ptr = 0;
    }
}

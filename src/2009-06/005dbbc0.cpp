// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
union any_pointer { void* obj_ptr; double d; };
struct vtable_base {
    void (*manager)(const any_pointer&, any_pointer&, int);
    void clear(any_pointer& functor) { if (manager) manager(functor, functor, 2); }
};
struct function_base {
    vtable_base* vtable;
    any_pointer functor;
    void clear() { if (vtable) { vtable->clear(functor); vtable = 0; } }
};
struct Clearer {
    void operator()(function_base* f);
};
void Clearer::operator()(function_base* f) { f->clear(); }

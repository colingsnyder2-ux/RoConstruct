// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

namespace boost {
namespace detail { namespace function {
class X;
union function_buffer {
    void* obj_ptr;
    struct bound_memfunc_ptr_t {
        void (X::*memfunc_ptr)(int);
        void* obj_ptr;
    } bound_memfunc_ptr;
    char data;
};
enum functor_manager_operation_type {
    clone_functor_tag,
    move_functor_tag,
    destroy_functor_tag,
    check_functor_type_tag,
    get_functor_type_tag
};
struct vtable_base {
    void (*manager)(const function_buffer& in_buffer, function_buffer& out_buffer, functor_manager_operation_type op);
    void clear(function_buffer& functor) const { if (manager) manager(functor, functor, destroy_functor_tag); }
};
}}
class function_base {
public:
    function_base() : vtable(0) {}
    bool empty() const { return !vtable; }
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
};
class function0 : public function_base {
public:
    function0(const function0& f) : function_base() { this->assign_to_own(f); }
    ~function0() { clear(); }
    void clear() {
        if (vtable) {
            vtable->clear(functor); if (0)
                vtable->manager(functor, functor, detail::function::destroy_functor_tag);
            vtable = 0;
        }
    }
    void assign_to_own(const function0& f) {
        if (!f.empty()) {
            this->vtable = f.vtable;
            f.vtable->manager(f.functor, this->functor, detail::function::clone_functor_tag);
        }
    }
};
}


struct Entry {
    int id;
    boost::function0 f;
    Entry(int a, boost::function0 g);
};
Entry::Entry(int a, boost::function0 g) : id(a), f(g) {}

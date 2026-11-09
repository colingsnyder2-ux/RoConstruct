// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace boost { namespace detail { namespace function {
union function_buffer {
    void* obj_ptr;
    double d;
    char data[16];
};
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag };
struct vtable_base {
    void (*manager)(const function_buffer& in_buffer, function_buffer& out_buffer, functor_manager_operation_type op);
};
} }
class function_base {
public:
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
    function_base() : vtable(0) {}
    bool empty() const { return !vtable; }
};
class function1 : public function_base {
public:
    function1(const function1& f) : function_base() { assign_to_own(f); }
    ~function1();
    void assign_to_own(const function1& f) {
        if (!f.empty()) {
            this->vtable = f.vtable;
            f.vtable->manager(f.functor, this->functor, detail::function::clone_functor_tag);
        }
    }
};
}
struct NamedFn {
    std::string name;
    boost::function1 fn;
    NamedFn(const NamedFn& o);
};
NamedFn::NamedFn(const NamedFn& o) : name(o.name), fn(o.fn) {}

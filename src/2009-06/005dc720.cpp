// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
#include <string>
#include <memory>
namespace boost {
namespace program_options { template<class C> class basic_option { char pad[0x60]; }; }
namespace detail { namespace function {
struct X;
union function_buffer {
    void* obj_ptr;
    struct type_t { const void* type; bool c; bool v; } type;
    void (*func_ptr)();
    struct bound_memfunc_ptr_t { void (X::*memfunc_ptr)(int); void* obj_ptr; } bound_memfunc_ptr;
    char data;
};
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag, check_functor_type_tag, get_functor_type_tag };
struct vtable_base {
    void (*manager)(const function_buffer& in_buffer, function_buffer& out_buffer, functor_manager_operation_type op);
    void clear(function_buffer& functor)
    {
        if (manager)
            manager(functor, functor, destroy_functor_tag);
    }
};
}}
class function_base {
public:
    function_base() : vtable(0) {}
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
};
template<class R, class T0, class A> class function1 : public function_base {
public:
    ~function1() { clear(); }
    void clear()
    {
        if (this->vtable) {
            this->vtable->clear(this->functor);
            this->vtable = 0;
        }
    }
};
}
typedef boost::function1<std::vector<boost::program_options::basic_option<char> >, std::vector<std::string>&, std::allocator<boost::function_base> > F;
template void std::_Destroy_range<std::allocator<F> >(F*, F*, std::allocator<F>&, std::_Nonscalar_ptr_iterator_tag);

// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// boost::function<void(bool)>::operator= with boost >= 1.35 function_buffer/manager (destroy_functor_tag = 2)
namespace boost {
namespace detail {
namespace function {
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
}
}
class function_base {
public:
    function_base() : vtable(0) {}
    bool empty() const { return !vtable; }
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
};
template<class R, class T0, class Allocator> class function1 : public function_base {
public:
    function1(const function1& f) : function_base() { assign_to_own(f); }
    ~function1() { clear(); }
    void swap(function1& other);
    void assign_to_own(const function1& f)
    {
        if (!f.empty()) {
            this->vtable = f.vtable;
            f.vtable->manager(f.functor, this->functor, detail::function::clone_functor_tag);
        }
    }
    void clear()
    {
        if (this->vtable) {
            this->vtable->clear(this->functor);
            this->vtable = 0;
        }
    }
};
template<typename Signature, typename Allocator> class function;
template<typename Allocator>
class function<void(bool), Allocator> : public function1<void, bool, Allocator> {
    typedef function1<void, bool, Allocator> base_type;
    typedef function self_type;
public:
    function(const self_type& f) : base_type(static_cast<const base_type&>(f)) {}
    self_type& operator=(const self_type& f)
    {
        self_type(f).swap(*this);
        return *this;
    }
};
}
namespace std { template<class T> class allocator; }
template class boost::function<void(bool), std::allocator<void> >;

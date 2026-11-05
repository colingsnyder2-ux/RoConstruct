// from server: 82% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
namespace detail { namespace function {
struct X;
union function_buffer {
    void* obj_ptr;
    struct type_t { const void* type; bool c; bool v; } type;
    void (*func_ptr)();
    struct bound_memfunc_ptr_t { void (X::*memfunc_ptr)(int); void* obj_ptr; } bound_memfunc_ptr;
    double d;
    char data[0x18];
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
    bool empty() const { return !vtable; }
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
};
template<class R> class function0 : public function_base {
public:
    function0(const function0& f) : function_base() { assign_to_own(f); }
    ~function0() { if (this->vtable) this->vtable->clear(this->functor); }
    void assign_to_own(const function0& f)
    {
        if (!f.empty()) {
            this->vtable = f.vtable;
            f.vtable->manager(f.functor, this->functor, detail::function::clone_functor_tag);
        }
    }
};
namespace signals {
class connection { public: ~connection(); void* con[3]; };
}
}
namespace RBX {
class Signal {
public:
    boost::signals::connection connect(int group, boost::function0<void> f);
};
template<class T> class Lazy { public: T* p; T* operator->(); };
class Explosion {
public:
    Lazy<Signal> signal;
    boost::signals::connection connect(int group, boost::function0<void> f);
};
boost::signals::connection Explosion::connect(int group, boost::function0<void> f)
{
    return signal->connect(group, f);
}
}

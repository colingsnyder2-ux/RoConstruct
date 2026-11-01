// from server: 100% by EspClaude
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
    function_base() {}
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
namespace _bi {
template<class T> struct value { T t_; };
template<class A1> struct list1 { A1 a1_; };
template<class R, class F, class L> struct bind_t { F f_; L l_; };
}
namespace detail { namespace function {
template<class F> struct basic_vtable {
    vtable_base base;
    void (*invoker)();
    bool assign_to(F f, function_buffer& functor) const;
};
void manage(const function_buffer&, function_buffer&, functor_manager_operation_type);
void invoke();
}}
class function1 : public function_base {
public:
    template<class F> function1(F f) { this->assign_to(f); }
    ~function1() { if (this->vtable) this->vtable->clear(this->functor); }
    template<class F> void assign_to(F f)
    {
        typedef detail::function::basic_vtable<F> vtable_type;
        static vtable_type stored_vtable = { { &detail::function::manage }, &detail::function::invoke };
        if (stored_vtable.assign_to(f, this->functor))
            this->vtable = &stored_vtable.base;
        else
            this->vtable = 0;
    }
};
namespace signals { class connection { public: ~connection(); void* con[3]; }; }
}
namespace RBX {
class Instance;
class Slot {
public:
    Slot(const boost::function1& f, Instance* owner);
    Slot(const Slot&);
    ~Slot();
    boost::function1 f;
    void* tracked[2];
};
class Signal {
public:
    void* pad;
    Instance* owner;
    boost::signals::connection connect(Slot slot);
    template<class F> boost::signals::connection connect(F f)
    {
        boost::function1 func(f);
        return connect(Slot(func, owner));
    }
};
struct Bound { void* d[6]; };
template boost::signals::connection Signal::connect<Bound>(Bound);
}

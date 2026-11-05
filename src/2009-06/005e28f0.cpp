// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
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
    double align;
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
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
    bool empty() const { return !vtable; }
};
template<class R> class function0 : public function_base {
public:
    function0(const function0& f)
    {
        this->vtable = 0;
        this->assign_to_own(f);
    }
    ~function0() { if (this->vtable) this->vtable->clear(this->functor); }
    void assign_to_own(const function0& f)
    {
        if (!f.empty()) {
            this->vtable = f.vtable;
            f.vtable->manager(f.functor, this->functor, detail::function::clone_functor_tag);
        }
    }
};
template<class T> struct type {};
namespace _bi {
template<class T> class value { public: T t_; T& get() { return t_; } };
struct list0 {
    template<class T> T& operator[](value<T>& v) const { return v.get(); }
};
template<class F> struct unwrapper { static F& unwrap(F& f, long) { return f; } };
template<class A1, class A2> struct storage2 { A1 a1_; A2 a2_; };
template<class A1, class A2> class list2 : private storage2<A1, A2> {
    typedef storage2<A1, A2> base_type;
public:
    template<class F, class A> void operator()(type<void>, F& f, A& a, int)
    {
        unwrapper<F>::unwrap(f, 0)(a[base_type::a1_], a[base_type::a2_]);
    }
};
}
}
typedef void (*ThreadFn)(std::string, boost::function0<void>);
template void boost::_bi::list2<boost::_bi::value<std::string>, boost::_bi::value<boost::function0<void> > >::operator()<ThreadFn, boost::_bi::list0>(boost::type<void>, ThreadFn&, boost::_bi::list0&, int);

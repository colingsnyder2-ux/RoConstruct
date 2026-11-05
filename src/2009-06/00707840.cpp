// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace std { template<class T> class allocator; }
namespace boost {
template<class T> class shared_ptr { public: T* px; void* pn; };
namespace detail { namespace function {
struct X;
union function_buffer {
    void* obj_ptr;
    struct type_t { const void* type; bool c; bool v; } type;
    void (*func_ptr)();
    struct bound_memfunc_ptr_t { void (X::*memfunc_ptr)(int); void* obj_ptr; } bound_memfunc_ptr;
    char data;
    double align_;
};
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag, check_functor_type_tag, get_functor_type_tag };
struct vtable_base {
    void (*manager)(const function_buffer&, function_buffer&, functor_manager_operation_type);
};
template<class R> struct basic_vtable0 {
    vtable_base base;
    R (*invoker)(function_buffer&);
    template<class F> bool assign_to(F f, function_buffer& functor);
};
template<class F> struct manager { static void manage(const function_buffer&, function_buffer&, functor_manager_operation_type); };
template<class F, class R> struct invoker0 { static R invoke(function_buffer&); };
}}
class function_base {
public:
    function_base() : vtable(0) {}
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
};
template<class R, class Alloc> class function0 : public function_base {
public:
    typedef detail::function::basic_vtable0<R> vtable_type;
    template<class Functor> function0(Functor f) : function_base() { this->assign_to(f); }
    template<class Functor> void assign_to(Functor f)
    {
        static vtable_type stored_vtable = { { &detail::function::manager<Functor>::manage }, &detail::function::invoker0<Functor, R>::invoke };
        if (stored_vtable.assign_to(f, functor))
            vtable = &stored_vtable.base;
        else
            vtable = 0;
    }
};
namespace _bi {
template<class T> class value { public: T t_; };
template<class A1> struct storage1 { A1 a1_; };
template<class A1, class A2> struct storage2 : public storage1<A1> { A2 a2_; storage2(const storage2&); ~storage2(); };
template<class A1, class A2, class A3> struct storage3 : public storage2<A1, A2> { A3 a3_; };
template<class A1, class A2, class A3> class list3 : private storage3<A1, A2, A3> {
public:
};
template<class R, class F, class L> class bind_t { public: F f_; L l_; };
}
}
struct Big2009 { double d; char pad[0x30]; };
typedef boost::_bi::bind_t<void, void (*)(boost::shared_ptr<int>, Big2009, int),
    boost::_bi::list3<boost::_bi::value<boost::shared_ptr<int> >, boost::_bi::value<Big2009>, boost::_bi::value<int> > > BindT;
template void boost::function0<void, std::allocator<boost::function_base> >::assign_to(BindT);

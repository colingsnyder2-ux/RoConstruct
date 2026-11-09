// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// boost::detail::function::function_obj_invoker0<bind_t<R, F, list2<...> >, R>::invoke
// codegen analog: the bound callable F occupies 8 bytes (list stored at bind_t+8 in target).

namespace boost {
template<class T> struct type {};
namespace _bi {
struct list0 {};
struct callable8 { void* first; void* second; };
template<class A1, class A2> struct list2 {
    A1 a1_;
    A2 a2_;
    template<class R, class F, class A> R operator()(type<R>, F& f, A& a, long);
};
template<class R, class F, class L> struct bind_t {
    F f_;
    L l_;
    R operator()() { list0 a; return l_(type<R>(), f_, a, 0); }
};
}
namespace detail { namespace function {
union function_buffer { void* obj_ptr; char data[16]; };
template<class FunctionObj, class R> struct function_obj_invoker0 {
    static R invoke(function_buffer& function_obj_ptr)
    {
        FunctionObj* f = reinterpret_cast<FunctionObj*>(function_obj_ptr.obj_ptr);
        return (*f)();
    }
};
}}
}

enum work_result { work_done };
typedef boost::_bi::bind_t<work_result, boost::_bi::callable8,
    boost::_bi::list2<void*, void*> > bound_type;
template struct boost::detail::function::function_obj_invoker0<bound_type, work_result>;

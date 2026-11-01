// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_) _InterlockedIncrement(&pi_->use_count_); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* get() const { return px; }
    T* operator->() const { return px; }
};
}
namespace boost {
template<class T> class weak_ptr { public: T* px; detail::shared_count pn; };
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
};
template<class R> struct basic_vtable0 {
    vtable_base base;
    R (*invoker)(function_buffer&);
    template<class F> bool assign_to(F f, function_buffer& functor);
};
template<class F> struct functor_manager {
    static void manage(const function_buffer& in_buffer, function_buffer& out_buffer, functor_manager_operation_type op);
};
template<class F, class R> struct void_function_obj_invoker0 {
    static R invoke(function_buffer& buf);
};
}
}
class function_base {
public:
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
};
template<class R> class function0 : public function_base {
public:
    typedef detail::function::basic_vtable0<R> vtable_type;
    template<class F> void assign_to(F f)
    {
        static vtable_type stored_vtable = { { &detail::function::functor_manager<F>::manage }, &detail::function::void_function_obj_invoker0<F, R>::invoke };
        if (stored_vtable.assign_to(f, this->functor)) this->vtable = &stored_vtable.base;
        else this->vtable = 0;
    }
};
namespace _bi {
template<class T> class value { public: T t_; };
template<class A1> struct list1 { A1 a1_; };
template<class R, class F, class L> class bind_t { public: F f_; L l_; };
}
}
namespace RBX { class Instance; }
typedef boost::_bi::bind_t<void, void (*)(boost::weak_ptr<RBX::Instance>), boost::_bi::list1<boost::_bi::value<boost::shared_ptr<RBX::Instance> > > > BindT;
template void boost::function0<void>::assign_to<BindT>(BindT);

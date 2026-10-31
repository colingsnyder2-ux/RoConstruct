// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#pragma intrinsic(_InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
}
}
namespace boost {
namespace detail {
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) _InterlockedIncrement(&pi_->use_count_); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
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
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
class function_base {
public:
    function_base() : vtable(0) {}
    bool empty() const { return !vtable; }
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
};
template<class R, class A> class function0 : public function_base {
public:
    function0(const function0& f) : function_base() { assign_to_own(f); }
    ~function0() { clear(); }
    void assign_to_own(const function0& f)
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
namespace _bi {
template<class T> class value { public: value(T const& t) : t_(t) {} T t_; };
template<class A1> struct storage1 { A1 a1_; };
template<class A1, class A2> struct storage2 : public storage1<A1> { A2 a2_; storage2(A1 a1, A2 a2); storage2(const storage2&); ~storage2(); };
template<class T> struct list_av_value { typedef value<T> type; };
template<class A1, class A2> class list2 : private storage2<A1, A2> {
public:
    list2(A1 a1, A2 a2);

};
}
}
namespace boost { namespace _bi {
template<class R, class F, class L> class bind_t {
public:
    bind_t(F f, L const& l) : f_(f), l_(l) {}
    F f_;
    L l_;
};
template<class A1, class A2> struct list_av_2 { typedef list2<value<A1>, value<A2> > type; };
}
template<class R, class B1, class B2, class A1, class A2>
_bi::bind_t<R, R (*)(B1, B2), typename _bi::list_av_2<A1, A2>::type>
bind(R (*f)(B1, B2), A1 a1, A2 a2)
{
    typedef R (*F)(B1, B2);
    typedef typename _bi::list_av_2<A1, A2>::type list_type;
    return _bi::bind_t<R, F, list_type>(f, list_type(a1, a2));
}
}
namespace std { template<class T> class allocator; }
namespace RBX {
class worker_thread {
public:
    enum work_result { done, more };
    struct data;
};
}
typedef boost::function0<RBX::worker_thread::work_result, std::allocator<boost::function_base> > WF;
typedef boost::shared_ptr<RBX::worker_thread::data> DP;
template boost::_bi::bind_t<void, void (*)(DP, const WF&), boost::_bi::list_av_2<DP, WF>::type> boost::bind<void, DP, const WF&, DP, WF>(void (*)(DP, const WF&), DP, WF);

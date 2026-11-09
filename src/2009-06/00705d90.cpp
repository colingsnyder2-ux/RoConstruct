// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
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
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
namespace function {
union function_buffer { void* obj_ptr; double d; char data[16]; };
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
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
};
template<class R, class A> class function0 : public function_base {
public:
    ~function0() { clear(); }
    void clear()
    {
        if (this->vtable) {
            this->vtable->clear(this->functor);
            this->vtable = 0;
        }
    }
};
namespace _bi {
template<class T> class value { public: T t_; };
template<class A1> struct storage1 { A1 a1_; };
template<class A1, class A2> struct storage2 : public storage1<A1> { A2 a2_; ~storage2() {} };
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
template struct boost::_bi::storage2<boost::_bi::value<boost::shared_ptr<RBX::worker_thread::data> >,
    boost::_bi::value<boost::function0<RBX::worker_thread::work_result, std::allocator<boost::function_base> > > >;
